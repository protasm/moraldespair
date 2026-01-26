#include <globals.h>

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

  if (moved) {
    set_this_player(this_object());
    command("look");
  }

  return moved;
}

int attempt_movement(string verb) {
  mapping directions;
  mapping exits;
  string direction;
  string destination;
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

  if (!function_exists("dest_dir", location))
    return 0;

  exits = location->dest_dir();

  if (!mapp(exits))
    return 0;

  destination = exits[direction];

  if (!stringp(destination))
    return 0;

  if (destination[0] != '/')
    destination = "/" + destination;

  moved = move(destination);

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
