#include <globals.h>

#include "player.h"

inherit "/inherit/base.c";

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

void show_location() {
  string command_path;
  object command_object;

  command_path = COMMAND_PREFIX + "look";

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
  write("\n" + PLAYER_PROMPT);

  input_to("handle_input");
}

void start_session() {
  repl();
}

void handle_input(string str) {
  string line, verb, arg, command_path, movement_arg;
  string *parts;
  object command_object;
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
  movement_arg = resolve_movement_alias(verb);

  if (movement_arg != "" || verb == "go") {
    if (movement_arg != "") {
      verb = "go";
      arg = movement_arg;
    }

    command_path = COMMAND_PREFIX + "go";

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

  command_path = COMMAND_PREFIX + verb;

  if (file_size(command_path + ".c") >= 0) {
    command_object = load_object(command_path);

    if (objectp(command_object))
      handled = call_other(command_object, "main", arg);
  }

  if (!handled)
    write("Unknown command.\n");

  repl();
}
