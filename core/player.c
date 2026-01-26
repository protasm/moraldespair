#include <globals.h>

#include "player.h"

inherit "/inherit/base.c";

int brief;
string name;
string account_name;

int move(mixed dest) {
  object old_env, new_env;
  int moved;

  old_env = efun::environment(efun::this_object());

  ::move(dest);

  new_env = efun::environment(efun::this_object());
  moved = 0;

  if (efun::objectp(new_env) && new_env != old_env)
    moved = 1;

  return moved;
}

int query_brief() {
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

void set_brief(int state) {
  if (state)
    brief = 1;
  else
    brief = 0;

  return;
}

int toggle_brief() {
  if (brief)
    brief = 0;
  else
    brief = 1;

  return brief;
}

void show_location() {
  string command_path;
  object command_object;

  command_path = COMMAND_PREFIX + "look";

  if (efun::file_size(command_path + ".c") >= 0) {
    command_object = efun::load_object(command_path);

    if (efun::objectp(command_object))
      efun::call_other(command_object, "main", "");
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

  if (!efun::stringp(direction))
    return "";

  return direction;
}

void repl() {
  efun::write(PLAYER_PROMPT);

  efun::input_to("handle_input");
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

  line = efun::trim(line);

  if (line == "") {
    repl();

    return;
  }

  parts = efun::explode(line, " ");
  verb = parts[0];

  if (efun::sizeof(parts) > 1)
    arg = efun::implode(parts[1..], " ");
  else
    arg = "";

  handled = 0;
  moved = 0;

  /* First: try a command file that exactly matches the verb. */
  if (verb != "go") {
    command_path = COMMAND_PREFIX + verb;

    if (efun::file_size(command_path + ".c") >= 0) {
      command_object = efun::load_object(command_path);

      if (efun::objectp(command_object))
        handled = efun::call_other(command_object, "main", arg);
    }

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
    location = efun::environment(efun::this_object());

    if (efun::objectp(location) && efun::function_exists("dest_dir", location)) {
      exits = location->dest_dir();

      if (efun::mapp(exits) && efun::stringp(exits[verb]))
        movement_arg = verb;
    }
  }

  if (movement_arg != "" || verb == "go") {
    if (movement_arg != "") {
      verb = "go";
      arg = movement_arg;
    }

    command_path = COMMAND_PREFIX + "go";

    if (efun::file_size(command_path + ".c") >= 0) {
      command_object = efun::load_object(command_path);

      if (efun::objectp(command_object))
        moved = efun::call_other(command_object, "main", arg);
    }

    if (moved)
      show_location();
    else
      efun::write("You can't go that way.\n");

    repl();

    return;
  }

  if (!handled)
    efun::write("Unknown command.\n");

  repl();
}
