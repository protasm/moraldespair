#include <globals.h>

//inherit "/inherit/base.c";

string player_name;
object player_object, account_object;

int try_command(string prefix, string verb, string arg) {
  string command_path;
  object command_object;
  int handled;

  handled = 0;
  command_path = prefix + verb;

  if (file_size(command_path + ".c") >= 0) {
    command_object = load_object(command_path);

    if (objectp(command_object))
      handled = call_other(command_object, "main", arg);
  }

  return handled;
}

string normalize_key(string value) {
  if (!stringp(value))
    return "";

  return lower_case(trim(value));
}

string player_file_path() {
  string username, player;

  username = account_object->username();
  player = normalize_key(player_name);

  if (username == "" || player == "")
    return "";

  return "/a/" + username + "/" + player + ".o";
}

mapping load_player_data() {
  mapping player;
  string path;
  string raw;

  path = player_file_path();

  if (path == "")
    return 0;

  if (file_size(path) <= 0)
    return 0;

  raw = read_file(path);

  if (!stringp(raw))
    return 0;

  player = restore_variable(raw);

  if (!mapp(player))
    return 0;

  return player;
}

int save_player_data(mapping player) {
  string path;
  string raw;

  if (!mapp(player))
    return 0;

  path = player_file_path();

  if (path == "")
    return 0;

  raw = save_variable(player);

  rm(path);

  return write_file(path, raw);
}

int move(mixed dest) {
  object old_env, new_env;
  int moved;

  old_env = environment(this_object());

  move_object(dest);

  new_env = environment(this_object());
  moved = 0;

  if (objectp(new_env) && new_env != old_env)
    moved = 1;

  return moved;
}

object query_player() {
  return player_object;
}

void set_player(object player) {
  player_object = player;

  return;
}

object query_account() {
  return account_object;
}

void set_account(object new_account) {
  account_object = new_account;

  return;
}

string query_name() {
  return player_name;
}

void set_name(string new_name) {
  player_name = normalize_key(new_name);

  return;
}

string query_display_name() {
  mapping player;

  player = load_player_data();

  if (!mapp(player))
    return "";

  return player["display_name"];
}

int set_display_name(string new_display_name) {
  mapping player;

  if (!stringp(new_display_name))
    return 0;

  player = load_player_data();

  if (!mapp(player))
    return 0;

  player["display_name"] = new_display_name;

  return save_player_data(player);
}

int query_brief() {
  mapping player;

  player = load_player_data();

  if (!mapp(player))
    return 0;

  return player["brief"];
}

int set_brief(int state) {
  mapping player;

  player = load_player_data();

  if (!mapp(player))
    return 0;

  if (state)
    player["brief"] = 1;
  else
    player["brief"] = 0;

  return save_player_data(player);
}

int toggle_brief() {
  mapping player;
  int brief;

  player = load_player_data();

  if (!mapp(player))
    return 0;

  brief = player["brief"];

  if (brief)
    player["brief"] = 0;
  else
    player["brief"] = 1;

  if (!save_player_data(player))
    return 0;

  return player["brief"];
}

int query_last_played() {
  mapping player;

  player = load_player_data();

  if (!mapp(player))
    return 0;

  return player["last_played"];
}

int set_last_played(int last_played) {
  mapping player;

  player = load_player_data();

  if (!mapp(player))
    return 0;

  player["last_played"] = last_played;

  return save_player_data(player);
}

void repl() {
  write(PLAYER_PROMPT);

  input_to("handle_input");
}

void start_session() {
  repl();
}

void show_location() {
  string command_path;
  object command_object;

  command_path = ACTION_PREFIX + "look";

  if (file_size(command_path + ".c") >= 0) {
    command_object = load_object(command_path);

    if (objectp(command_object))
      call_other(command_object, "main", "");
  }

  return;
}

string resolve_movement_alias(string verb) {
  mapping directions;
  string direction;

  directions = ([
    "north" : "north",
    "south" : "south",
    "east" : "east",
    "west" : "west",
    "northeast" : "northeast",
    "northwest" : "northwest",
    "southeast" : "southeast",
    "southwest" : "southwest",
    "up" : "up",
    "down" : "down",
    "n" : "north",
    "s" : "south",
    "e" : "east",
    "w" : "west",
    "ne" : "northeast",
    "nw" : "northwest",
    "se" : "southeast",
    "sw" : "southwest",
    "u" : "up",
    "d" : "down"
  ]);

  direction = directions[verb];

  if (!stringp(direction))
    return "";

  return direction;
}

int handle_command(string verb, string arg) {
  string command_path, movement_arg;
  object command_object, location;
  mapping exits;
  int handled, moved;

  handled = 0;
  moved = 0;

  if (verb != "go") {
    handled = try_command(ACTION_PREFIX, verb, arg);

    if (handled)
      return 1;
  }

  movement_arg = resolve_movement_alias(verb);

  if (movement_arg == "") {
    location = environment(this_object());

    if (objectp(location) && function_exists("dest_dir", location)) {
      exits = location->dest_dir();

      if (mapp(exits) && stringp(exits[verb]))
        movement_arg = verb;
    }
  }

  if (movement_arg != "" || verb == "go") {
    if (movement_arg != "") {
      verb = "go";
      arg = movement_arg;
    }

    command_path = ACTION_PREFIX + "go";

    if (file_size(command_path + ".c") >= 0) {
      command_object = load_object(command_path);

      if (objectp(command_object))
        moved = call_other(command_object, "main", arg);
    }

    if (moved)
      show_location();
    else
      write("You can't go that way.\n");

    return 1;
  }

  return 0;
}

void handle_input(string str) {
  string line, verb, arg;
  string *parts;
  object player;
  int handled;

  line = str;

  if (!line)
    line = "";

  line = trim(line);

  if (line == "") {
    repl();

    return;
  }

  parts = explode(line, " ");
  verb = parts[0];

  if (sizeof(parts) > 1)
    arg = implode(parts[1..], " ");
  else
    arg = "";

  handled = 0;
  player = query_player();

  if (objectp(player)) {
    handled = player->handle_command(verb, arg);
  }

  if (!handled)
    handled = handle_command(verb, arg);

  if (!handled)
    write("Unknown command.\n");

  repl();
}
