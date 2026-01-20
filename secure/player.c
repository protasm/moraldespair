#include "input_to.h"
#include "living.h"
#include "log.h"
#if defined(__TLS__)
#include "configuration.h"
#include "tls.h"
#endif

#define WIZ 1
#define ARCH 0

static object player_self; /* Player object reference for internal use. */
string title; /* Our official title. Wiz's can change it. */
string password; /* This players crypted password. */
static string pending_password; /* Temporary when setting new password. */
string al_title;
int intoxicated; /* How many ticks to stay intoxicated. */
int stuffed; /* How many ticks to stay stuffed. */
int soaked; /* How many ticks to stay soaked. */
int headache, max_headache;
string called_from_ip; /* IP number was used last time. */
string quests; /* A list of all quests. */
static int autosave_at; /* Time to autosave. */

static mixed saved_start_location; /* Temp... */
string mailaddr; /* Email address of player. */
static string last_referenced_item; /* Last thing referenced. */
int tot_value; /* Saved values of this player. */
static string current_working_path; /* Current directory. */
string access_list; /* What extra directories can be modified. */
int stats_is_updated;

#define MAX_SCAR 10
int scar;

static int logon();
static void move_player_to_start(mixed where);
static void move_player_to_start2(mixed where);
static void move_player_to_start3(mixed where);
void save_me(int value_items);
int illegal_patch(string what);
void add_standard_commands();
static void wiz_commands();
static void wiz_commands2();
mixed valid_read(string str, int lvl);
mixed valid_write(string str);
void drop_all(int verbose);
static void get_all(object from);
static int pick_item(string obj);
int drop_one_item(object ob);
void load_auto_obj(string str);
void compute_auto_str();
int vis();
string check_access_list(string top, string dir, string file);

#if defined(__TLS__)
void tls_init(int handshake_result);
#endif

#include "/secure/player/movement_messages.c"
#include "/secure/player/satiety.c"

/* Returns the player object version. */
string version() {
  return "2.04.05";
}

#if defined(__TLS__)
/* Handles TLS handshakes before normal logon. */
void tls_logon(int handshake_result) {
  if (handshake_result < 0) {
    printf("Can't establish a TLS/SSL encrypted connection: %s\n",
           tls_error(handshake_result));

    destruct(this_object());

    return;
  }

  logon();
}
#endif

/* ------------------------------------------------------------------------- */
/* Connection and login flow. */

/* Starts the login prompt flow. */
static int logon() {
  int count;
  int i;
  object *current_users;

  autosave_at = 500;

  cat("/WELCOME");

  current_users = users();
  count = 0;
  i = 0;

  while (i < sizeof(current_users)) {
    if (current_users[i] != this_object())
      count += 1;

    i += 1;
  }

  if (count == 0)
    write("Nobody is playing right now.\n");
  else if (count == 1)
    write("One person is playing right now.\n");
  else
    write(count + " people are playing right now.\n");

  write("What is your name? ");

  input_to("logon2", INPUT_PROMPT, "");

  call_out("time_out", 120);

  return 1;
}

static object existing_session;

/* Handles the duplicate session prompt. */
static void try_throw_out(string response) {
  object inventory_item;

  if (response == "" || (response[0] != 'y' && response[0] != 'Y')) {
    write("Welcome another time then !\n");

    destruct(this_object());

    return;
  }

  inventory_item = first_inventory(existing_session);

  while (inventory_item) {
    int item_weight;
    object next_item;

    item_weight = inventory_item->query_weight();
    next_item = next_inventory(inventory_item);

    if (!inventory_item->id("soul") && add_weight(item_weight)) {
      inventory_item->drop();

      if (inventory_item)
        move_object(inventory_item, this_player());
    }

    inventory_item = next_item;
  }

  inventory_item = environment(existing_session);

  existing_session->quit();

  if (restore_object("players/" + name))
    write("Points restored from the other object.\n");
  else
    destruct(existing_session);

  existing_session = 0;

  move_player_to_start(inventory_item);

#ifdef LOG_ENTER
  log_file("ENTER", " (throw)\n");
#endif
}

/* Validates player names for logon. */
int valid_name(string str) {
  int i, length;

  if (str == "logon") {
    write("Invalid name");

    return 0;
  }

  length = sizeof(str);

  if (length > 11) {
    write("Too long name.\n");

    return 0;

  }

  i = 0;

  while (i < length) {
    if (str[i] < 'a' || str[i] > 'z') {
      write("Invalid characters in name:" + str + "\n");

      write("Character number was " + (i + 1) + ".\n");

      return 0;
    }

    i += 1;
  }

  return 1;
}

/* Processes name input during logon. */
static void logon2(string str) {
  if (!str || str == "") {
    destruct(this_object());

    return;
  }

  if (name != "logon") {
    illegal_patch("logon2 " + name);

    destruct(this_object());

    return;
  }

  str = lower_case(str);

  if (!valid_name(str)) {
    input_to("logon2", INPUT_PROMPT, "Give name again: ");

    return;
  }

  if (restore_object("banish/" + str)) {
    write("That name is reserved.\n");

    destruct(this_object());

    return;
  }

  if (!restore_object("players/" + str)) {
    write("New character.\n");
  }

  autosave_at = age + 500;
  name = str;
  dead = ghost;
  player_self = this_player();

  if (is_invis)
    cap_name = "Someone";
  else
    cap_name = capitalize(name);

  local_weight = 0;
  armour_class = 0;
  name_of_weapon = 0;
  weapon_class = 0;

  if (level != -1)
    input_to("check_password", 1);
  else
    input_to("new_password", 1);

  write("Password: ");

  if (name == "guest")
    write("(just CR) ");

  attacker_ob = 0;

  alt_attacker_ob = 0;

  return;
}

/* ------------------------------------------------------------------------- */
/* Save/load lifecycle. */

/* Saves the character on demand. */
int save_character() {
  save_me(1);
  write("Ok.\n");
  return 1;
}

/* Initializes a fresh player object. */
void create() {
  if (player_self)
    return;

  if (creator(this_object())) {
    illegal_patch("Cloned player.c");

    destruct(this_object());

    return;
  }

  level = -1;
  name = "logon";
  cap_name = "Logon";
  msgin = "arrives";
  msgout = "leaves";
  mmsgin = "arrives in a puff of smoke";
  mmsgout = "disappears in a puff of smoke";
  title = "the title less";
  al_title = "neutral";
  gender = -1;
}

/* Returns the current hit points. */
int query_hit_point() {
  return hit_point;
}

/* Returns the short description for this player. */
string short() {
  if (is_invis)
    return 0;
  if (ghost)
    return "ghost of " + cap_name;
  if (frog)
    return cap_name + " the frog";
  return cap_name + " " + title + " (" + al_title + ")";
}

/* Prints scar details for this player. */
void show_scar() {
  int i, j, first, old_value;
  string *scar_desc;

  scar_desc =
      ({"left leg", "right leg", "nose", "left arm", "right arm", "left hand",
        "right hand", "forhead", "left cheek", "right cheek"});
  j = 1;
  first = 1;
  old_value = scar;
  i = 0;
  while (i < MAX_SCAR) {
    if (scar & j) {
      old_value &= ~j;
      if (first) {
        write(cap_name + " has a scar on " + query_possessive() + " " +
              scar_desc[i]);
        first = 0;
      } else if (old_value) {
        write(", " + query_possessive() + " " + scar_desc[i]);
      } else {
        write(" and " + query_possessive() + " " + scar_desc[i]);
      }
    }
    j *= 2;
    i += 1;
  }
  if (!first)
    write(".\n");
}

/* Adds a random scar for high level players. */
static void make_scar() {
  if (level < 10)
    return;
  scar |= 1 << random(MAX_SCAR);
}

/* Prints the long description for this player. */
void long() {
  string cap_pronoun;

  cap_pronoun = capitalize(query_pronoun());
  write(short() + ".\n");
  if (ghost || frog)
    return;
  show_scar();
  if (hit_point < max_hp / 10) {
    write(cap_pronoun + " is in very bad shape.\n");
    return;
  }
  if (hit_point < max_hp / 5) {
    write(cap_pronoun + " is in bad shape.\n");
    return;
  }
  if (hit_point < max_hp / 2) {
    write(cap_pronoun + " is not in a good shape.\n");
    return;
  }
  if (hit_point < max_hp - 20) {
    write(cap_pronoun + " is slightly hurt.\n");
    return;
  }
  write(cap_pronoun + " is in good shape.\n");
}

/* Displays player score details. */
int score(string arg) {
  string tmp;

  if (ghost) {
    write("You are in an immaterial state with no scores.\n");
    return 1;
  }

  if (arg) {
    write("Str: " + Str + "\n");
    write("Dex: " + Dex + "\n");
    write("Int: " + Int + "\n");
    write("Con: " + Con + "\n");
    return 1;
  }

  write("You have " + experience + " experience points, " + money +
        " gold coins, ");
  write(hit_point + " hit points(" + max_hp + ").\n");
  write(spell_points + " spell points.\n");
  if (hunter)
    write("You are hunted by " + hunter->query_name() + ".\n");
  tmp = intoxication_status_message();
  if (tmp)
    write(tmp);

  if (whimpy)
    write("Wimpy mode.\n");
  show_age();
  return 1;
}

/* Identifies the player based on names and visibility. */
int id(string str, int lvl) {
  if (level < 20)
    if (str == name || str == "ghost of " + name)
      return 1;
  if (is_invis && lvl <= level)
    return 0;
  if (ghost)
    return str == "ghost of " + name;
  if (str == name)
    return 1;
  return 0;
}

/* Returns the current title. */
string query_title() {
  return title;
}

/* Updates the player level, with wizard upgrades. */
void set_level(int lev) {
  object scroll;

  if (lev > 21 || lev < level && level >= 20) {
    illegal_patch("set_level");
    return;
  }
  level = lev;
  if (level == 20) {
    scroll = clone_object("doc/examples/init_scroll");
    move_object(scroll, player_self);
    tell_object(player_self, "You have been given a scroll containing valuable "
                            "information. Read it now!\n");
    tell_object(player_self, "Adding wizard commands...\n");
    wiz_commands();
  }
  if (level == 21) {
    tell_object(player_self, "Adding more wizard commands...\n");
    wiz_commands2();
  }
}

/* Sets or reports the player title. */
int set_title(string t) {
  if (!t) {
    write("Your title is " + title + ".\n");
    return 1;
  }
  title = t;
  return 1;
}

/* Escapes a string for embedding in LPC literals. */
static string escape_lpc_string(string str) {
  string escaped;
  int i;

  escaped = "";
  i = 0;
  while (i < sizeof(str)) {
    if (str[i] == '\\' || str[i] == '"') {
      escaped += "\\";
    }
    escaped += str[i..i];
    i += 1;
  }

  return escaped;
}

/* Updates room source files with new descriptions. */
static int update_room_description(string text, string prompt, string field_name,
                                   string setter_name, string update_label) {
  object room;
  string room_name, file_path, content, escaped, new_content, indent;
  string *lines;
  int i, j, found;

  if (!text) {
    write(prompt + " what?\n");
    return 1;
  }

  room = environment(this_player());

  if (!room) {
    write("You are nowhere.\n");
    return 1;
  }

  if (!function_exists(setter_name, room)) {
    write("This room cannot be updated.\n");
    return 1;
  }

  room_name = object_name(room);

  if (sscanf(room_name, "%s#%*s", file_path) == 1)
    room_name = file_path;

  file_path = "/" + room_name + ".c";
  file_path = valid_write(file_path);

  if (!file_path) {
    write("You can only update rooms you can write.\n");
    return 1;
  }

  if (file_size("/" + file_path) <= 0) {
    write("Room source file not found.\n");
    return 1;
  }

  content = read_file("/" + file_path);

  if (!content) {
    write("Unable to read room source file.\n");
    return 1;
  }

  lines = explode(content, "\n");
  escaped = escape_lpc_string(text);
  i = 0;
  found = 0;

  while (i < sizeof(lines)) {
    if (strstr(lines[i], field_name + " =") != -1) {
      indent = "";
      j = 0;

      while (j < sizeof(lines[i]) && lines[i][j] == ' ') {
        indent += " ";
        j += 1;
      }

      lines[i] = indent + field_name + " = \"" + escaped + "\";";
      found = 1;

      break;
    }

    i += 1;
  }

  if (!found) {
    write("No " + field_name + " assignment found.\n");
    return 1;
  }

  new_content = implode(lines, "\n") + "\n";

  if (!rm("/" + file_path)) {
    write("Unable to update room file.\n");
    return 1;
  }

  if (!write_file("/" + file_path, new_content)) {
    write("Unable to write updated room file.\n");
    return 1;
  }

  call_other(room, setter_name, text);

  write("Room " + update_label + " description updated.\n");

  return 1;
}

/* Updates the room long description. */
static int set_room_long(string str) {
  return update_room_description(str, "ld", "long_desc", "set_long", "long");
}

/* Updates the room short description. */
static int set_room_short(string str) {
  return update_room_description(str, "sd", "short_desc", "set_short",
                                 "short");
}

/* ------------------------------------------------------------------------- */
/* Wizard commands. */

/* Adds higher-level wizard commands. */
static void wiz_commands2() {
  if (this_object() != this_player())
    return;
  add_action("earmuffs", "earmuffs");
  add_action("makedir", "mkdir");
  add_action("removedir", "rmdir");
  add_action("pwd", "pwd");
  add_action("more", "more");
  add_action("echo_to", "echoto");
  add_action("echo", "echo");
  add_action("echo_all", "echoall");
  add_action("home", "home");
  add_action("remove_file", "rm");
  add_action("list_files", "ls");
  add_action("cat_file", "cat");
  add_action("edit", "ed");
  add_action("clone", "clone");
  add_action("destruct_local_object", "destruct");
  add_action("load", "load");
  add_action("tail_file", "tail");
  add_action("cd", "cd");
}

/* Adds standard wizard commands. */
static void wiz_commands() {
  if (this_object() != this_player())
    return;
  add_action("local_commands", "localcmd");
  add_action("wiz_score_list", "wizlist");
  add_action("force_player", "force");
  add_action("spell_zap", "zap");
  add_action("stat", "stat");
  add_action("heal", "heal");
  add_action("update_object", "update");
  add_action("set_title", "title");
  add_action("set_room_short", "sd");
  add_action("set_room_long", "ld");
  add_action("teleport", "goto");
  add_action("in_room", "in");
  add_action("emote", "emote");
  add_action("list_peoples", "people");
  add_action("setmmin", "setmmin");
  add_action("setmmout", "setmmout");
  add_action("setmin", "setmin");
  add_action("setmout", "setmout");
  add_action("review", "review");
  add_action("shut_down_game", "shutdown");
  add_action("trans", "trans");
  add_action("snoop_on", "snoop");
  add_action("invis", "invis");
  add_action("vis", "vis");
}

/* ------------------------------------------------------------------------- */
/* Shout and earmuffs helpers. */

#define SHOUT_OLD(x) shout(x)
#define SHOUT(x)                                                               \
  shout_message = x;                                                           \
  filter_objects(users(), "filter_tell", this_object())

static string shout_message;
static int listen_to_shouts_from_level;

/* Filters shouts for players with earmuffs. */
int filter_tell(object ob) {
  if (ob == this_player())
    return 0;
  return ob->catch_shout(shout_message);
}

/* Handles shout messages delivered to this player. */
int catch_shout(string str) {
  if (this_player()->query_level() >= listen_to_shouts_from_level) {
    tell_object(this_object(), str);
    return 1;
  }
  return 0;
}

/* Updates the minimum shout level to listen for. */
int listen_shout(int lev) {
  if (lev && lev <= level + 1)
    listen_to_shouts_from_level = lev;
  return listen_to_shouts_from_level;
}

/* Configures shout earmuffs. */
int earmuffs(string str) {
  int lev;

  if (str && sscanf(str, "%d", lev) == 1)
    listen_shout(lev);
  write("Earmuffs at level " + listen_to_shouts_from_level + ".\n");
  return 1;
}

/* Broadcasts a wizard echo to everyone. */
static int echo_all(string str) {
  if (!str) {
    write("Echoall what?\n");
    return 1;
  }
  SHOUT(str + "\n");
  write("You echo: " + str + "\n");
  return 1;
}

/* Broadcasts a local echo. */
static int echo(string str) {
  if (!str) {
    write("Echo what?\n");
    return 1;
  }
  say(str + "\n");
  write("You echo: " + str + "\n");
  return 1;
}

/* Sends an echo to a single player. */
static int echo_to(string str) {
  object ob;
  string who;
  string msg;

  if (!str || sscanf(str, "%s %s", who, msg) != 2) {
    write("Echoto what ?\n");
    return 1;
  }
  ob = find_living(lower_case(who));
  if (!ob) {
    write("No player with that name.\n");
    return 1;
  }
  tell_object(ob, msg + "\n");
  write("You echo: " + msg + "\n");
  return 1;
}

/* ------------------------------------------------------------------------- */
/* Wizard travel and session commands. */

/* Teleports the wizard to a target. */
int teleport(string dest) {
  object target;

  if (!dest) {
    write("Goto where ?\n");
    return 1;
  }
  target = find_living(dest);
  if (target) {
    target = environment(target);
    if (!is_invis)
      say(cap_name + " " + mmsgout + ".\n");
    move_object(player_self, target);
    if (!is_invis)
      say(cap_name + " " + mmsgin + ".\n");
    if (brief) {
      write(target->short() + "\n");
    } else {
      string room_short;
      string *room_lines;

      room_short = target->short();
      if (room_short) {
        room_lines = explode(room_short, "\n");
        if (sizeof(room_lines))
          write(room_lines[0] + "\n");
      }
      target->long();
    }
    target = first_inventory(target);
    while (target) {
      if (target != this_object()) {
        string short_str;

        short_str = target->short();
        if (short_str)
          write(short_str + ".\n");
      }
      target = next_inventory(target);
    }
    return 1;
  }
  dest = valid_read(dest, WIZ);
  if (!dest || file_size("/" + dest + ".c") <= 0) {
    write("Invalid monster name or file name: " + dest + "\n");
    return 1;
  }
  move_player("X#" + dest);
  return 1;
}

/* Saves and removes the player from the game. */
int quit() {
  save_me(0);
  drop_all(1);
  write("Saving ");
  write(capitalize(name));
  write(".\n");
  if (!is_invis) {
    say(cap_name + " left the game.\n");
  }
  destruct(this_object());
  return 1;
}

/* Handles the kill command. */
int kill(string str) {
  object target;

  if (ghost)
    return 0;
  if (!str) {
    write("Kill what ?\n");
    return 1;
  }
  target = present(lower_case(str), environment(this_player()));
  if (!target) {
    write("No " + str + " here !\n");
    return 1;
  }
  if (!living(target)) {
    write(str + " is not a living thing !\n");
    say(cap_name + " tries foolishly to attack " + str + ".\n");
    return 1;
  }
  if (target == this_object()) {
    write("What ? Attack yourself ?\n");
    return 1;
  }
  if (attacker_ob == target) {
    write("Yes, yes.\n");
    return 1;
  }
  attack_object(target);
  return 1;
}

/* Handles say and apostrophe speech. */
int communicate(string str) {
  string verb;

  verb = query_verb();
  if (str == 0)
    str = "";
  if (verb[0] == "'"[0])
    str = verb[1..] + " " + str;
  write("Ok.\n");
  if (ghost) {
    say(short() + " says: " + str + ".\n");
    return 1;
  }
  say(cap_name + " says: " + str + "\n");
  return 1;
}

/* Handles player heart beat updates. */
static void heart_beat() {
  if (ghost)
    return;
  age += 1;
  if (age > autosave_at) {
    if (!brief)
      write("Autosave.\n");
    save_me(1);
    autosave_at = age + 500;
  }
  handle_intoxication_emotes();

  if (hit_point < max_hp || spell_points < max_sp || intoxicated || headache) {
    time_to_heal -= 1;
    if (time_to_heal < 0) {
      handle_headache_recovery();
      if (hit_point < max_hp) {
        hit_point += 1;
        if (intoxicated)
          hit_point += 3;
        if (hit_point > max_hp)
          hit_point = max_hp;
      }
      if (spell_points < max_sp) {
        spell_points += 1;
        if (intoxicated)
          spell_points += 3;
        if (spell_points > max_sp)
          spell_points = max_sp;
      }
      handle_intoxication_recovery();
      time_to_heal = INTERVAL_BETWEEN_HEALING;
    }
  }

  decay_food_and_drink();

  if (attacker_ob)
    attack();
  if (attacker_ob && whimpy && hit_point < max_hp / 5)
    run_away();
}

/* ------------------------------------------------------------------------- */
/* Alignment and morality. */

/* Adjusts alignment based on actions. */
void add_alignment(int a) {
  if (!intp(a)) {
    write("Bad type argument to add_alignment.\n");
    return;
  }
  alignment = alignment * 9 / 10 + a;
  if (level > 20)
    return;
  if (alignment > KILL_NEUTRAL_ALIGNMENT * 100) {
    al_title = "saintly";
    return;
  }
  if (alignment > KILL_NEUTRAL_ALIGNMENT * 20) {
    al_title = "good";
    return;
  }
  if (alignment > KILL_NEUTRAL_ALIGNMENT * 4) {
    al_title = "nice";
    return;
  }
  if (alignment > -KILL_NEUTRAL_ALIGNMENT * 4) {
    al_title = "neutral";
    return;
  }
  if (alignment > -KILL_NEUTRAL_ALIGNMENT * 20) {
    al_title = "nasty";
    return;
  }
  if (alignment > -KILL_NEUTRAL_ALIGNMENT * 100) {
    al_title = "evil";
    return;
  }
  al_title = "demonic";
}

/* Sets absolute alignment directly. */
void set_al(int a) {
  if (!intp(a))
    return;
  alignment = a;
}

/* Sets the alignment title string. */
void set_alignment(string al) {
  al_title = al;
}

/* Checks for sufficient light. */
static int test_dark() {
  if (set_light(0) <= 0) {
    write("It is too dark.\n");
    return 1;
  }
  return 0;
}

/* ------------------------------------------------------------------------- */
/* Inventory and item handling. */

/* Handles putting items in containers. */
int put(string str) {
  int item_weight;
  string item;
  string container;
  object item_object;
  object container_object;

  if (!str)
    return 0;
  if (test_dark())
    return 1;
  if (sscanf(str, "%s in %s", item, container) != 2) {
    write("put what ?\n");
    return 1;
  }
  container = lower_case(container);
  container_object = present(container, this_player());
  if (!container_object)
    container_object = present(container, environment(this_player()));
  if (!container_object) {
    write("There are no " + container + "s here!\n");
    return 1;
  }
  if (!container_object->can_put_and_get()) {
    write("You can't do that.\n");
    return 1;
  }
  item = lower_case(item);
  item_object = present(item, this_player());
  if (!item_object) {
    write("You have no " + item + "!\n");
    return 1;
  }
  if (item_object == container_object)
    return 0;
  if (item_object->prevent_insert())
    return 1;
  if (item_object->drop())
    return 1;
  item_weight = item_object->query_weight();
  if (container_object->add_weight(item_weight)) {
    environment(item_object)->add_weight(-item_weight);
    move_object(item_object, container_object);
    say(cap_name + " puts the " + item + " in the " + container + ".\n");
    write("Ok.\n");
    last_referenced_item = item;
    return 1;
  }
  write("There is not room for more.\n");
  return 1;
}

/* Handles picking up items. */
int pick_up(string str) {
  string item;
  string container;
  object item_object;
  object container_object;
  int item_weight;

  if (!str) {
    write("What ?\n");
    return 1;
  }
  if (ghost) {
    write("You fail.\n");
    return 1;
  }
  if (test_dark())
    return 1;
  if (str == "all") {
    get_all(environment());
    return 1;
  }
  if (sscanf(str, "%s from %s", item, container) != 2) {
    pick_item(str);
    return 1;
  }
  container_object = present(lower_case(container));
  if (!container_object) {
    write("There is no " + container + " here.\n");
    return 1;
  }
  if (!container_object->can_put_and_get()) {
    write("You can't do that!\n");
    return 1;
  }
  item_object = present(item, container_object);
  if (!item_object) {
    write("There is no " + item + " in the " + container + ".\n");
    return 1;
  }
  if (!item_object->get(item)) {
    write("You can not take " + item + " from " + container + ".\n");
    return 1;
  }
  item_weight = item_object->query_weight();
  if (!add_weight(item_weight)) {
    write("You can not carry more.\n");
    return 1;
  }
  container_object->add_weight(-item_weight);
  move_object(item_object, player_self);
  write("Ok.\n");
  say(cap_name + " takes " + item + " from " + container + ".\n");
  return 1;
}

/* Handles picking up a single item. */
static int pick_item(string obj) {
  object ob;
  int item_weight;

  obj = lower_case(obj);
  if (environment(this_player())->id(obj)) {
    write("You can't take that.\n");
    return 1;
  }
  ob = present(obj, environment(this_player()));
  if (!ob) {
    write("That is not here.\n");
    return 1;
  }
  if (ghost) {
    write("You fail.\n");
    return 1;
  }
  if (environment(ob) == player_self) {
    write("You already have it!\n");
    return 1;
  }
  if (ob->get() == 0) {
    write("You can not take that!\n");
    return 1;
  }
  item_weight = ob->query_weight();
  if (add_weight(item_weight)) {
    move_object(ob, player_self);
    say(cap_name + " takes " + obj + ".\n");
    last_referenced_item = obj;
    write("Ok.\n");
    return 1;
  }
  write("You can't carry that much.\n");
  return 1;
}

/* Handles the drop command. */
int drop_thing(mixed obj) {
  string item_name;
  string container_name;
  object item_object;

  if (!obj) {
    write("What ?\n");
    return 1;
  }
  if (obj == "all") {
    drop_all(1);
    return 1;
  }
  if (sscanf(obj, "%s in %s", item_name, container_name) == 2) {
    put(obj);
    return 1;
  }
  if (obj == "money" || obj == "all money") {
    drop_all_money(1);
    return 1;
  }
  item_name = obj;
  item_object = present(lower_case(obj), this_player());
  if (!item_object) {
    write("That is not here.\n");
    return 1;
  }
  if (drop_one_item(item_object)) {
    last_referenced_item = item_name;
    write("Ok.\n");
    say(cap_name + " drops the " + item_name + ".\n");
  }
  return 1;
}

/* Adjusts local weight and validates limits. */
int add_weight(int w) {
  int max;

  max = level + 10;
  if (frog)
    max = max / 2;
  if (w + local_weight > max)
    return 0;
  if (w + local_weight < 0)
    return 0;
  local_weight += w;
  return 1;
}

/* Executes commands temporarily in another room. */
static int in_room(string str) {
  string room;
  object old_room;
  string cmd;

  if (!str)
    return 0;
  if (sscanf(str, "%s %s", room, cmd) != 2) {
    write("Usage: in ROOM CMD\n");
    return 1;
  }
  room = valid_read(room, WIZ);
  if (!room) {
    write("Invalid file name.\n");
    return 1;
  }
  old_room = environment();
  move_object(player_self, room);
  command(cmd);
  if (old_room)
    move_object(player_self, old_room);
  else
    write("Could not go back again.\n");
  return 1;
}

/* Shouts to all players. */
int shout_to_all(string str) {
  if (spell_points < 0) {
    write("You are low on power.\n");
    return 1;
  }
  if (level < 20)
    spell_points -= 30;
  if (!str) {
    write("Shout what ?\n");
    return 1;
  }
  if (ghost) {
    write("You fail.\n");
    return 1;
  }
  if (!frog) {
    SHOUT(cap_name + " shouts: " + str + "\n");
  } else {
    SHOUT(cap_name + " the frog shouts: " + "Hriibit! Hrriiibit!" + "\n");
  }
  write("Ok.\n");
  return 1;
}

/* Emits an emote in the room. */
static int emote(string str) {
  if (!str) {
    write("emote what ?\n");
    return 1;
  }
  say(cap_name + " " + str + "\n");
  write("Ok.\n");
  return 1;
}

/* Lists inventory items. */
int inventory() {
  object ob;

  if (test_dark())
    return 1;
  ob = first_inventory(player_self);
  while (ob) {
    string str;

    str = ob->short();
    if (str) {
      write(capitalize(str) + ".\n");
      last_referenced_item = str;
    }
    ob = next_inventory(ob);
  }
  return 1;
}

/* Handles look/examine commands. */
int look(string str) {
  object ob, ob_tmp;
  string item;
  int max;

  if (test_dark())
    return 1;
  if (!str) {
    environment()->long();
    ob = first_inventory(environment());
    max = MAX_LIST;
    while (ob && max > 0) {
      if (ob != player_self) {
        string short_str;

        short_str = ob->short();
        if (short_str) {
          max -= 1;
          write(short_str + ".\n");
          last_referenced_item = short_str;
        }
      }
      ob = next_inventory(ob);
    }
    return 1;
  }
  if (sscanf(str, "at %s", item) == 1 || sscanf(str, "in %s", item) == 1) {
    int weight;

    item = lower_case(item);
    ob = present(item, this_player());
    if (!ob && environment(this_player())->id(item))
      ob = environment(this_player());
    if (!ob)
      ob = present(item, environment(this_player()));
    if (!ob) {
      write("There is no " + item + " here.\n");
      return 1;
    }
    last_referenced_item = item;
    ob->long(item);
    weight = ob->query_weight();
    if (!living(ob)) {
      if (weight >= 5)
        write("It looks very heavy.\n");
      else if (weight >= 3)
        write("It looks heavy.\n");
    }
    if (!ob->can_put_and_get(item))
      return 1;
    if (living(ob)) {
      object special;

      special = first_inventory(ob);
      while (special) {
        string extra_str;

        extra_str = special->extra_look();
        if (extra_str)
          write(extra_str + ".\n");
        special = next_inventory(special);
      }
    }
    ob_tmp = first_inventory(ob);
    while (ob_tmp && ob_tmp->short() == 0)
      ob_tmp = next_inventory(ob_tmp);
    if (ob_tmp) {
      if (living(ob)) {
        write("\t" + capitalize(item) + " is carrying:\n");
      } else
        write("\t" + capitalize(item) + " contains:\n");
    }
    max = MAX_LIST;
    ob = first_inventory(ob);
    while (ob && max > 0) {
      string sh;

      sh = ob->short();
      if (sh)
        write(sh + ".\n");
      ob = next_inventory(ob);
      max -= 1;
    }
    return 1;
  }
  write("Look AT something, or what ?\n");
  return 1;
}

/* Routes examine to look at. */
static int examine(string str) {
  return look("at " + str);
}

/* Validates password during logon. */
static void check_password(string p) {
  write("\n");
  remove_call_out("time_out");
  if (password == 0)
    write("You have no password ! Set it with the 'password' cmd.\n");
  else if (name != "guest" && crypt(p, password) != password) {
    write("Wrong password!\n");
    destruct(player_self);
    return;
  }
  move_player_to_start(0);
#ifdef LOG_ENTER
  log_file("ENTER", cap_name + ", " + ctime(time())[4..15] + ".\n");
#endif
}

/* Prompts for a new password on new character creation. */
static void new_password(string p) {
  write("\n");
  if (!p || p == "") {
    write("Try again another time then.\n");
    destruct(player_self);
    return;
  }
  if (sizeof(p) < 6) {
    write("The password must have at least 6 characters.\n");
    input_to("new_password", 1);
    write("Password: ");
    return;
  }
  if (password == 0) {
    password = p;
    input_to("new_password", 1);
    write("Password: (again) ");
    return;
  }
  remove_call_out("time_out");
  if (password != p) {
    write("You changed !\n");
    destruct(player_self);
    return;
  }
  password = crypt(password, 0);
  "daemon/advancement_d"->advance(0);
  set_level(1);
  set_str(1);
  set_con(1);
  set_int(1);
  set_dex(1);
  hit_point = max_hp;
  move_player_to_start(0);
#ifdef LOG_NEWPLAYER
  log_file("NEWPLAYER", cap_name + ".\n");
#endif
}

/* Handles moving the player into the game. */
static void move_player_to_start(mixed where) {
  if (!mailaddr || mailaddr == "") {
    write("Please enter your email address (or 'none'): ");
    saved_start_location = where;
    input_to("getmailaddr");
    return;
  }

  move_player_to_start2(where);
}

/* Sets the player's mail address. */
void set_mailaddr(string addr) {
  mailaddr = addr;
}

/* Returns the player's mail address. */
string query_mailaddr() {
  return mailaddr;
}

/* Receives mail address input. */
static void getmailaddr(string maddr) {
  mailaddr = maddr;

  move_player_to_start2(saved_start_location);
}

/* Moves player into gender selection. */
static void move_player_to_start2(mixed where) {
  if (gender == -1) {
    write("Are you, male, female or other: ");
    input_to("getgender", 0);
    return;
  }
  move_player_to_start3(where);
}

/* Handles gender selection. */
static void getgender(string gender_string) {
  gender_string = lower_case(gender_string);
  if (gender_string[0] == 'm') {
    write("Welcome, Sir!\n");
    set_male();
  } else if (gender_string[0] == 'f') {
    write("Welcome, Madam!\n");
    set_female();
  } else if (gender_string[0] == 'o') {
    write("Welcome, Creature!\n");
    set_neuter();
  } else {
    write("Sorry, but that is too weird for this game!\n");
    write("Are you, male, female or other (type m, f or o): ");
    input_to("getgender");
    return;
  }

  move_player_to_start3(saved_start_location);
}

/* Finalizes entering the game world. */
static void move_player_to_start3(mixed where) {
  object ob;
  string tmp_name;

  tmp_name = name;
  name = 0;
  existing_session = find_player(tmp_name);
  name = tmp_name;
  enable_commands();
  if (existing_session) {
    write("You are already playing !\n");
    write("Throw the other copy out ? ");
    input_to("try_throw_out");
    return;
  }
  if (!stats_is_updated) {
    int tmp;

    tmp = level;
    if (tmp > 20)
      tmp = 20;
    set_str(tmp);
    set_int(tmp);
    set_con(tmp);
    set_dex(tmp);
    stats_is_updated = 1;
  }

  set_heart_beat(1);

  add_standard_commands();

  if (level >= 20)
    wiz_commands();
  if (level >= 21)
    wiz_commands2();

  move_object(clone_object("obj/soul"), player_self);

  if (tot_value) {
    write("You find " + tot_value + " coins of your lost money!\n");

    money += tot_value;

    tot_value = 0;
  }

  cat("/NEWS");

  if (where)
    move_object(player_self, where);
  else {
    move_object(player_self, "chapter/prologue/area/ruined/sanctuary");

    load_auto_obj(auto_load);
  }

  if (is_invis && level < 20)
    vis();

  if (!is_invis)
    say(cap_name + " enters the game.\n");
  else
    write("YOU ARE INVISIBLE !\n\n");
  
  if (level >= 21)
    cat("/WIZNEWS");

  if (query_ip_number() != called_from_ip && called_from_ip) {
  }

  called_from_ip = query_ip_number();
  ob = first_inventory(environment());

  while (ob) {
    if (ob != this_object()) {
      string sh;

      sh = ob->short();

      if (sh)
        write(sh + ".\n");
    }

    ob = next_inventory(ob);
  }

  current_working_path = "players/" + name;

  set_living_name(name);
}

/* ------------------------------------------------------------------------- */
/* File and editor utilities. */

/* Lists files in the current path. */
static int list_files(string path) {
  if (!path)
    path = "/" + current_working_path;

  if (path != "/")
    path = path + "/.";

  ls(path);

  return 1;
}

/* Tails a file. */
int tail_file(string path) {
  if (!path)
    return 0;
  if (!tail(path))
    return 0;
  return 1;
}

/* Cats a file. */
int cat_file(string path) {
  object here;
  string here_path;

  if (!path)
    return 0;
  if (path == "here") {
    here = environment(this_object());

    if (!here) {
      write("You are nowhere.\n");

      return 1;
    }

    here_path = file_name(here);

    if (!here_path) {
      write("No such file.\n");

      return 1;
    }

    path = here_path;
  }
  if (!cat(path))
    write("No such file.\n");
  return 1;
}

/* Handles help lookups. */
static int help(string what) {
  if (what == "wizard" && level >= 20) {
    cat("/doc/wiz_help");
    return 1;
  }
  if (what) {
    cat("/doc/helpdir/" + what);
    return 1;
  }
  cat("/doc/help");
  return 1;
}

/* Sends a tell to another player. */
static int tell(string str) {
  object ob;
  string who;
  string msg;

  if (ghost) {
    write("You fail.\n");
    return 1;
  }
  if (spell_points < 0) {
    write("You are low on power.\n");
    return 1;
  }
  if (level < 20)
    spell_points -= 5;
  if (!str || sscanf(str, "%s %s", who, msg) != 2) {
    write("Tell what ?\n");
    return 1;
  }
  last_referenced_item = lower_case(who);
  ob = find_living(last_referenced_item);
  if (!ob) {
    write("No player with that name.\n");
    return 1;
  }
  tell_object(ob, cap_name + " tells you: " + msg + "\n");
  write("Ok.\n");
  return 1;
}

/* Sends a whisper to another player. */
int whisper(string str) {
  object ob;
  string who;
  string msg;

  if (ghost) {
    write("You fail.\n");
    return 1;
  }
  if (!str || sscanf(str, "%s %s", who, msg) != 2) {
    write("Whisper what ?\n");
    return 1;
  }
  last_referenced_item = lower_case(who);
  ob = find_living(last_referenced_item);
  if (!ob || !present(last_referenced_item, environment(this_player()))) {
    write("No player with that name in this room.\n");
    return 1;
  }
  tell_object(ob, cap_name + " whispers to you: " + msg + "\n");
  write("Ok.\n");
  say(cap_name + " whispers something to " + who + ".\n", ob);
  return 1;
}

/* Lists online players with details. */
int list_peoples() {
  object *list;
  int i, active_count;

  list = users();
  write("There are now " + sizeof(list) + " players");
  for (i = 0, active_count = 0; i < sizeof(list); i++)
    if (query_idle(list[i]) >= 5 * 60)
      active_count++;
  if (active_count)
    write(" (" + (sizeof(list) - active_count) + " active)");
  write(". " + query_load_average() + "\n");
  for (i = 0; i < sizeof(list); i++) {
    string name;

    name = list[i]->query_real_name();
    if (!name)
      name = list[i]->query_name();
    if (!name)
      name = "logon";
    name = capitalize(name);
    if (list[i]->short() == 0)
      name = "(" + name + ")";
    if (sizeof(name) < 8)
      name = name + "\t";
    write(query_ip_number(list[i]) + "\t" + name + "\t" +
          list[i]->query_level() + "\t");
    active_count = list[i]->query_age();
    if (active_count / 43200 > 9)
      write(active_count / 43200 + " D");
    else if (active_count / 43200 > 0)
      write(active_count / 43200 + "  D");
    else if (active_count / 1800 > 9)
      write(active_count / 1800 + " h");
    else if (active_count / 1800 > 0)
      write(active_count / 1800 + "  h");
    else if (active_count / 30 > 9)
      write(active_count / 30 + " m");
    else
      write(active_count / 30 + "  m");
    if (query_idle(list[i]) >= 5 * 60)
      write(" I\t");
    else
      write("\t");
    if (environment(list[i]))
      write(object_name(environment(list[i])));
    write("\n");
  }
  return 1;
}

/* Forces an object to reload on next use. */
static int update_object(string str) {
  object ob;

  if (!str) {
    write("Update what object ?\n");
    return 1;
  }
  str = valid_read(str, WIZ);
  if (!str) {
    write("Invalid file name.\n");
    return 1;
  }
  ob = find_object(str);
  if (!ob) {
    write("No such object.\n");
    return 1;
  }
  destruct(ob);
  write(str + " will be reloaded at next reference.\n");
  return 1;
}

/* Opens the editor at a specified file. */
static int edit(string file) {
  if (!file) {
    ed();
    return 1;
  }
  file = valid_write(file);
  if (!file) {
    write("You can only edit your own files.\n");
    return 1;
  }
  ed(file);
  return 1;
}

/* Heals a specified player. */
static int heal(string name) {
  object ob;

  if (!name)
    return 0;
  last_referenced_item = lower_case(name);
  ob = find_living(last_referenced_item);
  if (!ob) {
    write("No such person is playing now.\n");
    return 1;
  }
  ob->heal_self(100000);
  tell_object(ob, "You are healed by " + cap_name + ".\n");
  write("Ok.\n");
  return 1;
}

/* Shows stats for a specified player. */
static int stat(string name) {
  object ob;

  if (!name)
    return 0;
  last_referenced_item = lower_case(name);
  ob = present(name, environment());
  if (!ob || !living(ob))
    ob = find_living(last_referenced_item);
  if (!ob) {
    write("No such person is playing now.\n");
    return 1;
  }
  ob->show_stats();
  return 1;
}

/* Drops a specified object from inventory. */
int drop_one_item(object ob) {
  int weight;

  if (ob->drop())
    return 0;
  weight = ob->query_weight();
  if (!weight)
    weight = 0;
  add_weight(-weight);
  move_object(ob, environment(player_self));
  return 1;
}

/* Drops all inventory items. */
void drop_all(int verbose) {
  object ob;
  object next_ob;

  if (!player_self || !living(player_self))
    return;
  ob = first_inventory(player_self);
  while (ob) {
    string out;

    next_ob = next_inventory(ob);
    last_referenced_item = ob->short();
    if (drop_one_item(ob) && verbose) {
      out = last_referenced_item + ".\n";
      say(cap_name + " drops " + out);
      tell_object(player_self, "drop: " + out);
    }
    ob = next_ob;
  }
}

/* Shuts down the game. */
static int shut_down_game(string str) {
  if (!str) {
    write("You must give a shutdown reason as argument.\n");
    return 1;
  }
  shout("Game is shut down by " + capitalize(name) + ".\n");
#ifdef LOG_SHUTDOWN
  log_file("GAME_LOG",
           ctime(time()) + " Game shutdown by " + name + "(" + str + ")\n");
#endif
  shutdown();
  return 1;
}

/* Changes the player password. */
static int change_password(string str) {
  if (password != 0 && !str) {
    write("Give old password as an argument.\n");
    return 1;
  }
  if (password != 0 && password != crypt(str, password)) {
    write("Wrong old password.\n");
    return 1;
  }
  pending_password = 0;
  input_to("change_password2", 1);
  write("New password: ");
  return 1;
}

/* Handles confirmation for new passwords. */
static void change_password2(string str) {
  if (!str) {
    write("Password not changed.\n");
    return;
  }
  if (pending_password == 0) {
    pending_password = str;
    input_to("change_password2", 1);
    write("Again: ");
    return;
  }
  if (pending_password != str) {
    write("Wrong! Password not changed.\n");
    return;
  }
  password = crypt(pending_password, 0);
  pending_password = 0;
  write("Password changed.\n");
}

/* Logs actions when inside a player directory. */
void smart_report(string str) {
  string who;
  string current_room;

  current_room = object_name(environment(this_object()));
  if (sscanf(current_room, "players/%s/", who) != 1)
    return;
  log_file(who + ".rep", current_room + " " + str + "\n");
}

/* Logs a bug report. */
static int bug(string str) {
  if (!str) {
    write("Give an argument.\n");
    return 1;
  }
  log_file("BUGS", "\n");
  log_file("BUGS", cap_name + " (" + object_name(environment(this_object())) +
                       "):\n");
  log_file("BUGS", str + "\n");
  smart_report("Bug " + cap_name + "\n" + str);
  write("Ok.\n");
  return 1;
}

/* Logs a typo report. */
static int typo(string str) {
  if (!str) {
    write("Give an argument.\n");
    return 1;
  }
  log_file("TYPO", cap_name + " (" + object_name(environment(this_object())) +
                       "):\n");
  log_file("TYPO", str + "\n");
  smart_report("Typo " + cap_name + "\n" + str);
  write("Ok.\n");
  return 1;
}

/* Logs an idea report. */
static int idea(string str) {
  if (!str) {
    write("Give an argument.\n");
    return 1;
  }
  log_file("IDEA", cap_name + ":\n");
  log_file("IDEA", str + "\n");
  smart_report("Idea " + cap_name + "\n" + str);
  write("Ok.\n");
  return 1;
}

/* Starts conversation mode. */
static int converse() {
  write("Give '**' to stop.\n");
  write("]");
  input_to("converse_more");
  return 1;
}

/* Handles lines during conversation mode. */
static void converse_more(string str) {
  string cmd;

  if (str == "**") {
    write("Ok.\n");
    return;
  }
  if (str[0] == '!') {
    sscanf(str, "!%s", cmd);
    command(cmd);
  } else if (str != "") {
    say(cap_name + " says: " + str + "\n");
  }
  write("]");
  input_to("converse_more");
}

/* Toggles whimpy mode. */
static int toggle_whimpy() {
  whimpy = !whimpy;
  if (whimpy)
    write("Wimpy mode.\n");
  else
    write("Brave mode.\n");
  return 1;
}

/* Returns whether brief mode is enabled. */
int query_brief() {
  return brief;
}

/* Toggles brief mode. */
int toggle_brief() {
  brief = !brief;
  if (brief)
    write("Brief mode.\n");
  else
    write("Verbose mode.\n");
  return 1;
}

/* Adds experience points. */
void add_exp(int e) {
#ifdef LOG_EXP
  if (this_player() && this_player() != this_object() &&
      query_ip_number(this_player()) && level < 20 && e >= ROOM_EXP_LIMIT)
    log_file("EXPERIENCE", ctime(time()) + " " + name + "(" + level + ") " +
                               e + " exp by " +
                               this_player()->query_real_name() + "(" +
                               this_player()->query_level() + ")" + "\n");
#endif
  experience += e;
  if (level <= 19)
    add_worth(e);
}

/* Handles the second life state on death. */
int second_life() {
#if 1
  object death_mark;
#endif

  if (level >= 20)
    return illegal_patch("second_life");
  make_scar();
  ghost = 1;
  if (level > 1)
    level = level - 1;
  if (Str > 1)
    set_str(Str - 1);
  if (Con > 1)
    set_con(Con - 1);
  if (Dex > 1)
    set_dex(Dex - 1);
  if (Int > 1)
    set_int(Int - 1);
  msgin = "drifts around";
  msgout = "blows";
  headache = 0;
  intoxicated = 0;
  stuffed = 0;
  soaked = 0;
  hunter = 0;
  hunted = 0;
#ifdef LOG_KILLS
  if (attacker_ob)
    log_file("KILLS", name + "(" + level + ")" + " killed by " +
                          attacker_ob->short() + "(" +
                          attacker_ob->query_real_name() +
                          "), creator: " + creator(attacker_ob) + "\n");
#endif
  attacker_ob = 0;
  alt_attacker_ob = 0;
  tell_object(player_self, "\nYou die.\nYou have a strange feeling.\n" +
                              "You can see your own dead body from above.\n\n");

#if 1
  death_mark = clone_object("/domain/lp-245/room/death/death_mark");
  move_object(death_mark, player_self);
#endif
  return 1;
}

/* Removes ghost state from the player. */
int remove_ghost() {
  if (!ghost)
    return 0;
  write("You feel a very strong force.\n");
  write("You are sucked away...\n");
  write("You reappear in a more solid form.\n");
  say("Some mist disappears.\n");
  say(cap_name + " appears in a solid form.\n");
  ghost = 0;
  dead = 0;
  msgin = "arrives";
  msgout = "leaves";
  save_me(1);
  return 1;
}

/* Transfers another living to the current room. */
static int trans(string str) {
  object ob;
  string out;

  if (!str)
    return 0;
  ob = find_living(str);
  if (!ob) {
    write("No such living thing.\n");
    return 1;
  }
  last_referenced_item = str;
  tell_object(ob, "You are magically transfered somewhere.\n");
  out = ob->query_mmsgin();
  if (!out)
    out = ob->query_name() + " arrives in a puff of smoke.\n";
  else
    out = ob->query_name() + " " + out + ".\n";
  say(out);
  write(out);
  move_object(ob, environment(this_object()));
  return 1;
}

/* Stops hunting mode. */
int stop_hunting_mode() {
  if (!hunted) {
    write("You are not hunting anyone.\n");
    return 1;
  }
  hunted->stop_hunter();
  hunted = 0;
  write("Ok.\n");
  return 1;
}

/* Handles drinking alcohol with full strength. */
/* Casts a magic missile. */
int spell_missile(string str) {
  object ob;

  if (test_dark())
    return 1;
  if (level < 5)
    return 0;
  if (!str)
    ob = attacker_ob;
  else
    ob = present(lower_case(str), environment(this_player()));
  if (!ob || !living(ob)) {
    write("At whom ?\n");
    return 1;
  }
  if (ob == player_self) {
    write("What ?");
    return 1;
  }
  missile_object(ob);
  return 1;
}

/* Casts a shock spell. */
int spell_shock(string str) {
  object ob;

  if (test_dark())
    return 1;
  if (level < 10)
    return 0;
  if (!str)
    ob = attacker_ob;
  else
    ob = present(lower_case(str), environment(this_player()));
  if (!ob || !living(ob)) {
    write("At whom ?\n");
    return 1;
  }
  if (ob == player_self) {
    write("What ?");
    return 1;
  }
  shock_object(ob);
  return 1;
}

/* Casts a fireball spell. */
int spell_fire_ball(string str) {
  object ob;

  if (test_dark())
    return 1;
  if (level < 15)
    return 0;
  if (!str)
    ob = attacker_ob;
  else
    ob = present(lower_case(str), environment(this_player()));
  if (!ob || !living(ob)) {
    write("At whom ?\n");
    return 1;
  }
  if (ob == player_self) {
    write("What ?");
    return 1;
  }
  fire_ball_object(ob);
  return 1;
}

/* Casts a zap spell. */
static int spell_zap(string str) {
  object ob;

  if (!str)
    ob = attacker_ob;
  else
    ob = present(lower_case(str), environment(this_player()));
  if (!ob || !living(ob)) {
    write("At whom ?\n");
    return 1;
  }
  zap_object(ob);
  return 1;
}

/* Handles giving items or coins to others. */
int give_object(string str) {
  string item, dest;
  object item_ob, dest_ob;
  int weight;
  int coins;

  if (!str)
    return 0;
  if (test_dark())
    return 1;
  if (sscanf(str, "%d coins to %s", coins, dest) == 2)
    item = 0;
  else if (sscanf(str, "1 coin to %s", dest) == 1)
    coins = 1;
  else if (sscanf(str, "coin to %s", dest) == 1)
    coins = 1;
  else if (sscanf(str, "one coin to %s", dest) == 1)
    coins = 1;
  else if (sscanf(str, "%s to %s", item, dest) != 2) {
    write("Give what to whom ?\n");
    return 1;
  }
  dest = lower_case(dest);
  if (item) {
    item = lower_case(item);
    item_ob = present(item, this_player());
    if (!item_ob) {
      write("There are no " + item + " here.\n");
      return 1;
    }
    last_referenced_item = item;
    if (environment(item_ob) == this_object() && item_ob->drop() == 1) {
      return 1;
    } else {
      if (!item_ob->get()) {
        write("You can't get that !\n");
        return 1;
      }
    }
  }
  dest_ob = present(dest, environment(this_player()));
  if (!dest_ob) {
    write("There is no " + capitalize(dest) + " here.\n");
    return 1;
  }
  if (!living(dest_ob)) {
    write("You can't do that.\n");
    return 1;
  }
  if (!item) {
    if (coins <= 0 && level < 20)
      return 0;
    if (money < coins) {
      write("You don't have that much money.\n");
      return 1;
    }
    money -= coins;
    if (coins > 1000 && level < 20)
      save_me(1);
    dest_ob->add_money(coins);
    tell_object(dest_ob,
                cap_name + " gives you " + coins + " gold coins.\n");
    write("Ok.\n");
    return 1;
  }
  weight = item_ob->query_weight(0);
  if (!dest_ob->add_weight(weight)) {
    write(capitalize(dest) + " can't carry any more.\n");
    return 1;
  }
  add_weight(-weight);
  move_object(item_ob, dest_ob);
  say(cap_name + " gives " + item + " to " + capitalize(dest) + ".\n");
  write("Ok.\n");
  return 1;
}

/* Picks up all items from a container. */
static void get_all(object from) {
  object ob, next_ob;

  ob = first_inventory(from);
  while (ob) {
    string item;

    next_ob = next_inventory(ob);
    item = ob->short();
    if (item && ob->get()) {
      int weight;

      weight = ob->query_weight();
      if (add_weight(weight)) {
        write(item + ": Ok.\n");
        move_object(ob, this_object());
        say(cap_name + " takes: " + item + ".\n");
      } else {
        write(item + ": Too heavy.\n");
      }
      last_referenced_item = item;
    }
    ob = next_ob;
  }
}

/* Forces another player to execute a command. */
static int force_player(string str) {
  string who, what;
  object ob;

  if (!str)
    return 0;
  if (sscanf(str, "%s to %s", who, what) == 2 ||
      sscanf(str, "%s %s", who, what) == 2) {
    ob = find_living(who);
    if (!ob) {
      write("No such player.\n");
      return 1;
    }
    tell_object(ob, cap_name + " force you to: " + what + "\n");
    command(what, ob);
    write("Ok.\n");
    return 1;
  }
  return 0;
}

/* Clones a specified object. */
int clone(string str) {
  object ob;

  if (!str) {
    write("Clone what object ?\n");
    return 1;
  }
  str = valid_read(str, WIZ);
  if (!str) {
    write("Invalid file.\n");
    return 1;
  }
  ob = clone_object(str);
  say(cap_name + " fetches something from another dimension.\n");
  move_object(ob, environment());
  if (ob->get())
    transfer(ob, player_self);
  write("Ok.\n");
  return 1;
}

/* Performs a high level pose. */
int pose() {
  if (level >= 15) {
    write("You send a ball of fire into the sky.\n");
    say(cap_name + " makes a magical gesture.\n");
    say("A ball of fire explodes in the sky.\n");
    return 1;
  }
  return 0;
}

/* Destructs a local object. */
static int destruct_local_object(string str) {
  object ob;

  if (!str) {
    write("Destruct what ?\n");
    return 1;
  }
  str = lower_case(str);
  ob = present(str, this_player());
  if (!ob)
    ob = present(str, environment(this_player()));
  if (!ob) {
    write("No " + str + " here.\n");
    return 1;
  }
  say(ob->short() + " is disintegrated by " + cap_name + ".\n");
  destruct(ob);
  write("Ok.\n");
  return 1;
}

/* Loads an object into memory. */
static int load(string str) {
  if (!str) {
    write("Load what ?\n");
    return 1;
  }
  str = valid_read(str, WIZ);
  if (!str) {
    write("Invalid file name.\n");
    return 1;
  }
  load_object(str);
  write("Ok.\n");
  return 1;
}

/* Starts snooping a player. */
static int snoop_on(string str) {
  object ob;
  int ob_level;

  if (!str) {
    snoop();
    return 1;
  }
  ob = find_player(str);
  if (!ob) {
    write("No such player.\n");
    return 1;
  }
  ob_level = ob->query_level();
  if (ob_level >= level) {
    write("You fail.\n");
    return 1;
  }
  snoop(ob);
  return 1;
}

/* Makes the player invisible. */
int invis() {
  if (is_invis) {
    tell_object(this_object(), "You are already invisible.\n");
    return 1;
  }
  is_invis = 1;
  tell_object(this_object(), "You are now invisible.\n");
  say(cap_name + " " + mmsgout + ".\n", this_object());
  cap_name = "Someone";
  return 1;
}

/* Makes the player visible again. */
int vis() {
  if (!is_invis) {
    tell_object(this_object(), "You are not invisible.\n");
    return 1;
  }
  is_invis = 0;
  tell_object(this_object(), "You are now visible.\n");
  cap_name = capitalize(name);
  say(cap_name + " " + mmsgin + ".\n", this_object());
  return 1;
}

/* Returns the player to their home. */
static int home() {
  move_player("home#players/" + name + "/workroom");
  return 1;
}

/* Validates write access for paths. */
mixed valid_write(string str) {
  string who, file, owner;
  string domain, area;

  owner = name;

  if (previous_object() && previous_object() != this_object())
    if (sscanf(object_name(previous_object()), "players/%s/", who) == 1)
      owner = who;

  if (str[0] != '/') {
    if (previous_object() && previous_object() != this_object()) {
      str = "players/" + owner + "/" + str;

      return str;
    }

    if (current_working_path != "")
      str = "/" + current_working_path + "/" + str;
    else
      str = "/" + str;
  }

  if (sscanf(str, "/domain/%s/area/%s/%s", domain, area, file) == 3)
    return str;

  if (sscanf(str, "/chapter/prologue/area/%s/%s", area, file) == 2)
    return str;

  if (sscanf(str, "/players/%s/%s", who, file) == 2) {
    if (who == owner || level > 23)
      return "players/" + who + "/" + file;

    return check_access_list("players/", who, file);
  }

  if (sscanf(str, "/log/%s", who) == 1) {
    if (level < 24 && who[0] >= 'A' && who[0] <= 'Z')
      return 0;

    return "log/" + who;
  }

  if (sscanf(str, "/open/%s", file) == 1)
    return "open/" + file;

  if (sscanf(str, "/ftp/%s", file) == 1)
    return "ftp/" + file;

  return 0;
}

/* Validates read access for paths. */
mixed valid_read(string str, int lvl) {
  string who, file;
  int i;

  i = sizeof(str) - 1;
  while (i > 0) {
    if (str[i] == '.' && str[i - 1] == '.') {
      write("Illegal to have '..' in path.\n");
      return 0;
    }
    i -= 1;
  }
  file = valid_write(str);
  if (file)
    return file;
  if (str[0] != '/') {
    if (current_working_path == "")
      str = "/" + str;
    else
      str = "/" + current_working_path + "/" + str;
  }
  if (lvl == ARCH) {
    if (sscanf(str, "/players/%s", file) == 1 && level < 23)
      return 0;
  }
  if (sscanf(str, "/%s", file) == 1)
    return file;
  write("Bad file name: " + str + "\n");
  return 0;
}

/* Displays wizard list info. */
static int wiz_score_list(string arg) {
  if (arg)
    wizlist(arg);
  else
    wizlist();
  return 1;
}

/* Removes a file. */
static int remove_file(string str) {
  if (!str)
    return 0;
  rm(str);
  return 1;
}

/* Runs local commands helper. */
static int local_commands() {
  localcmd();
  return 1;
}

/* Computes total inventory values. */
int compute_values(object ob) {
  int v;

  v = 0;
  while (ob) {
    int tmp;
    object next_ob;

    next_ob = next_inventory(ob);
    tmp = ob->query_value();
    if (tmp > 1000)
      tmp = 1000;
    v += tmp;
    if (ob && first_inventory(ob))
      v += compute_values(first_inventory(ob));
    ob = next_ob;
  }
  return v;
}

/* Saves the player to disk. */
void save_me(int value_items) {
  if (value_items)
    tot_value = compute_values(first_inventory(this_object()));
  else
    tot_value = 0;

  compute_auto_str();

  save_object("players/" + name);
}

/* Logs illegal patch attempts. */
int illegal_patch(string what) {
  write("You are struck by a mental bolt from the interior of the game.\n");
  write(what + "\n");

  log_file("ILLEGAL", ctime(time()) + ":\n");
  log_file("ILLEGAL", this_player()->query_real_name() + " " + what + "\n");

  return 0;
}

/* Loads autoloaded objects from a saved string. */
void load_auto_obj(string str) {
  string file, argument, rest;
  object ob;

  while (str && str != "") {
    if (sscanf(str, "%s:%s^!%s", file, argument, rest) != 3) {
      write("Auto load string corrupt.\n");

      return;
    }

    str = rest;
    ob = find_object(file);

    if (!ob) {
      write("Can't autoload '" + file + "': not in game.\n");

      continue;
    }

    ob = clone_object(file);

    if (argument)
      ob->init_arg(argument);

    move_object(ob, this_object());
  }
}

/* Computes the autoload string for inventory. */
void compute_auto_str() {
  object ob;
  string str;

  auto_load = "";
  ob = first_inventory(this_object());

  while (ob) {
    str = ob->query_auto_load();
    ob = next_inventory(ob);

    if (!str)
      continue;

    auto_load = auto_load + str + "^!";
  }
}

/* Queries a quest for existence or state. */
mixed query_quests(string str) {
  string tmp, rest, rest_tmp;
  int i;

  if (str == 0)
    return quests;

  rest = quests;

  while (rest) {
    if (str == rest)
      return 1;

    i = sscanf(rest, "%s#%s", tmp, rest_tmp);

    if (i == 0)
      return 0;

    if (tmp == str)
      return 1;

    if (i == 1)
      return 0;

    rest = rest_tmp;
  }

  return 0;
}

/* Marks a quest as completed. */
int set_quest(string q) {
  if (!q)
    return 0;

  if (query_quests(q))
    return 0;

#ifdef LOG_SET_QUEST
  if (previous_object()) {
    log_file("QUESTS", name + ": " + q + " from " +
                           object_name(previous_object()) + "\n");

    if (this_player() && this_player() != this_object() &&
        query_ip_number(this_player()))
      log_file("QUESTS",
               "Done by " + this_player()->query_real_name() + "\n");
  }
#endif /* LOG_SET_QUEST */

  if (quests == 0)
    quests = q;
  else
    quests = quests + "#" + q;

  return 1;
}

/* Returns the player real name. */
string query_real_name() {
  return name;
}

/* Handles logon timeout. */
void time_out() {
  write("Time out\n");
  destruct(this_object());
}

/* Lists online players by short description. */
int who() {
  object *list;
  int i;

  list = users();
  i = 0;
  while (i < sizeof(list)) {
    string sh;

    sh = list[i]->short();
    if (sh == 0 && level >= 20)
      write("(" + list[i]->query_real_name() + ")\n");
    else if (sh)
      write(sh + "\n");
    i += 1;
  }
  return 1;
}

/* Changes the current working path. */
static int cd(string str) {
  if (str == "..") {
    int i;

    if (current_working_path == "")
      return 0;
    i = sizeof(current_working_path) - 1;
    while (i > 0 && current_working_path[i] != '/')
      i -= 1;
    if (i == 0)
      current_working_path = "";
    else
      current_working_path = current_working_path[0..i - 1];
  } else if (!str)
    current_working_path = "players/" + name;
  else if (str == "/")
    current_working_path = "";
  else if (str[0] != '/') {
    if (current_working_path == "")
      current_working_path = str;
    else
      current_working_path += "/" + str;
  } else {
    current_working_path = str[1..];
  }
  write("/" + current_working_path + "\n");
  return 1;
}

#define CHUNK 16

static string more_file; /* Used by the more command. */
static int more_line;

/* Starts the more pager. */
int more(string str) {
  if (!str)
    return 0;
  more_file = str;
  more_line = 1;
  if (cat(more_file, more_line, CHUNK) == 0) {
    write("No such file\n");
    return 1;
  }
  input_to("even_more");
  write("More: (line " + (CHUNK + 1) + ") ");
  return 1;
}

/* Continues the more pager. */
static void even_more(string str) {
  if (str == "" || str == "d")
    more_line += CHUNK;
  else if (str == "q") {
    write("Ok.\n");
    return;
  } else if (str == "u") {
    more_line -= CHUNK;
    if (more_line < 1)
      more_line = 1;
  }
  if (cat(more_file, more_line, CHUNK) == 0) {
    more_file = 0;
    write("EOF\n");
    return;
  }
  write("More: (line " + (more_line + CHUNK) + ") ");
  input_to("even_more");
}

/* Prints the current working directory. */
int pwd() {
  write("/" + current_working_path + "\n");
  return 1;
}

/* Creates a directory. */
int makedir(string str) {
  if (!str)
    return 0;
  if (mkdir(str))
    write("Ok.\n");
  else
    write("Fail.\n");
  return 1;
}

/* Removes a directory. */
int removedir(string str) {
  if (!str)
    return 0;
  if (rmdir(str))
    write("Ok.\n");
  else
    write("Fail.\n");
  return 1;
}

/* Returns the current path string. */
string query_path() {
  return current_working_path;
}

/* Checks access list for a path. */
string check_access_list(string top, string dir, string file) {
  string tmp1, tmp2;

  if (!access_list)
    return 0;
  if (sscanf(access_list, "%s" + dir + "#%s", tmp1, tmp2) == 2)
    return top + dir + "/" + file;
  return 0;
}

/* Sets or reports the email address. */
static int set_email(string str) {
  if (!str) {
    write("Your official electric mail address is: " + mailaddr + "\n");
    return 1;
  }
  mailaddr = str;
  write("Changed your email address.\n");
  return 1;
}

/* Registers standard player commands. */
void add_standard_commands() {
  add_action("set_email", "email");
  add_action("give_object", "give");
  add_action("quit", "quit");
  add_action("communicate", "say");
  add_action("communicate", "'", 1);
  add_action("shout_to_all", "shout");
  add_action("put", "put");
  add_action("pick_up", "get");
  add_action("pick_up", "take");
  add_action("drop_thing", "drop");
  add_action("inventory", "i");
  add_action("look", "look");
  add_action("examine", "examine");
  add_action("examine", "exa", 1);
  add_action("help", "help");
  add_action("tell", "tell");
  add_action("whisper", "whisper");
  add_action("change_password", "password");
  add_action("idea", "idea");
  add_action("typo", "typo");
  add_action("bug", "bug");
  add_action("converse", "converse");
  add_action("toggle_brief", "brief");
  add_action("who", "who");
#if defined(__TLS__)
  add_action("tls", "tls");
#endif
}

#if defined(__TLS__)
/* Prints TLS connection details. */
static int tls(string str) {
  int secure_now;
  mixed *cipher_info;

  secure_now = tls_query_connection_state(this_object()) > 0;
  if (secure_now) {
    cipher_info = tls_query_connection_info(this_object());
    printf("You are presently connected via a TLS secured connection.\n"
           "Protocol: %s Ciphersuite: %s\n",
           to_string(cipher_info[TLS_PROT]),
           to_string(cipher_info[TLS_CIPHER]));
  } else {
    printf("You are presently connected via an insecure telnet connection.\n");
  }
  return 1;
}
#endif
