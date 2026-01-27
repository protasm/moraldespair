#include <globals.h>

#include "player.h"

inherit "/inherit/base.c";

int brief;
string name;
string account_name;
object curr_avatar;

string normalize_key(string value) {
  if (!stringp(value))
    return "";

  return lower_case(trim(value));
}

string account_file_path() {
  string username;

  username = normalize_key(account_name);

  if (username == "")
    return "";

  return "/a/" + username + "/account.o";
}

mapping load_account_data() {
  mapping account;
  string path;
  string raw;

  path = account_file_path();

  if (path == "")
    return 0;

  if (file_size(path) <= 0)
    return 0;

  raw = read_file(path);

  if (!stringp(raw))
    return 0;

  account = restore_variable(raw);

  if (!mapp(account))
    return 0;

  return account;
}

int save_account_data(mapping account) {
  string path;
  string raw;

  if (!mapp(account))
    return 0;

  path = account_file_path();

  if (path == "")
    return 0;

  raw = save_variable(account);

  rm(path);

  return write_file(path, raw);
}

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

int move(mixed dest) {
  object old_env, new_env;
  int moved;

  old_env = environment(this_object());

  ::move(dest);

  new_env = environment(this_object());
  moved = 0;

  if (objectp(new_env) && new_env != old_env)
    moved = 1;

  return moved;
}

int query_brief() {
  object avatar;

  avatar = query_curr_avatar();

  if (objectp(avatar))
    return avatar->query_brief();

  return brief;
}

string query_name() {
  return name;
}

void set_name(string new_name) {
  name = new_name;

  return;
}

string query_account() {
  return account_name;
}

void set_account(string new_account) {
  account_name = new_account;

  return;
}

object query_curr_avatar() {
  return curr_avatar;
}

void set_curr_avatar(object avatar) {
  curr_avatar = avatar;

  return;
}

string query_account_display_name() {
  mapping account;

  account = load_account_data();

  if (!mapp(account))
    return "";

  return account["display_name"];
}

int set_account_display_name(string new_display_name) {
  mapping account;

  if (!stringp(new_display_name))
    return 0;

  account = load_account_data();

  if (!mapp(account))
    return 0;

  account["display_name"] = new_display_name;

  return save_account_data(account);
}

string query_account_email() {
  mapping account;

  account = load_account_data();

  if (!mapp(account))
    return "";

  return account["email"];
}

int set_account_email(string new_email) {
  mapping account;
  string normalized;

  if (!stringp(new_email))
    return 0;

  normalized = normalize_key(new_email);

  if (normalized == "")
    return 0;

  account = load_account_data();

  if (!mapp(account))
    return 0;

  account["email"] = normalized;

  return save_account_data(account);
}

string query_account_password_hash() {
  mapping account;

  account = load_account_data();

  if (!mapp(account))
    return "";

  return account["password_hash"];
}

int set_account_password_hash(string new_hash) {
  mapping account;

  if (!stringp(new_hash))
    return 0;

  account = load_account_data();

  if (!mapp(account))
    return 0;

  account["password_hash"] = new_hash;

  return save_account_data(account);
}

string *query_account_avatars() {
  mapping account;
  string *avatars;

  account = load_account_data();

  if (!mapp(account))
    return ({});

  avatars = account["avatars"];

  if (!pointerp(avatars))
    return ({});

  return avatars;
}

int set_account_avatars(string *avatars) {
  mapping account;

  if (!pointerp(avatars))
    return 0;

  account = load_account_data();

  if (!mapp(account))
    return 0;

  account["avatars"] = avatars;

  return save_account_data(account);
}

int query_account_last_login() {
  mapping account;

  account = load_account_data();

  if (!mapp(account))
    return 0;

  return account["last_login"];
}

int set_account_last_login(int last_login) {
  mapping account;

  account = load_account_data();

  if (!mapp(account))
    return 0;

  account["last_login"] = last_login;

  return save_account_data(account);
}

void set_brief(int state) {
  object avatar;

  avatar = query_curr_avatar();

  if (objectp(avatar)) {
    avatar->set_brief(state);

    return;
  }

  if (state)
    brief = 1;
  else
    brief = 0;

  return;
}

int toggle_brief() {
  object avatar;

  avatar = query_curr_avatar();

  if (objectp(avatar))
    return avatar->toggle_brief();

  if (brief)
    brief = 0;
  else
    brief = 1;

  return brief;
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

void repl() {
  write(PLAYER_PROMPT);

  input_to("handle_input");
}

void start_session() {
  repl();
}

void handle_input(string str) {
  string line, verb, arg, command_path, movement_arg;
  string *parts;
  object command_object, location;
  mapping exits;
  int handled, moved;

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
  moved = 0;

  /* First: try account-level commands. */
  handled = try_command(COMMAND_PREFIX, verb, arg);

  if (handled) {
    repl();

    return;
  }

  /* Second: try chapter-level actions. */
  if (verb != "go") {
    handled = try_command(ACTION_PREFIX, verb, arg);

    if (handled) {
      repl();

      return;
    }
  }

  /*
   * Second: treat the verb as movement only after all command files are
   * exhausted. This includes standard direction aliases and any room-defined
   * exits like "door" or "pylus".
   */
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

    repl();

    return;
  }

  if (!handled)
    write("Unknown command.\n");

  repl();
}
