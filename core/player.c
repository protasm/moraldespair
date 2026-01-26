#include <globals.h>

inherit "/inherit/base.c";

int attempt_movement(string verb) {
  mapping directions;
  string direction;
  object location;
  int moved;

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

  if (!direction)
    return 0;

  location = environment(this_object());

  if (!objectp(location))
    return 0;

  if (!function_exists("move_direction", location))
    return 0;

  moved = call_other(location, "move_direction", direction);

  if (!moved)
    write("You can't go that way.\n");

  return 1;
}

void repl() {
  write("> ");

  input_to("handle_input");
}

void start_session() {
  repl();
}

void handle_input(string str) {
  string line, verb, arg, command_path;
  string *parts;
  object command_object;
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

  command_path = COMMAND_PREFIX + verb;

  if (file_size(command_path + ".c") >= 0) {
    command_object = load_object(command_path);

    if (objectp(command_object))
      handled = call_other(command_object, "main", arg);
  }

  if (!handled)
    handled = attempt_movement(verb);

  if (!handled)
    write("Unknown command.\n");

  repl();
}
