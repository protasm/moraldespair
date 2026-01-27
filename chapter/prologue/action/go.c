inherit "/core/command";

void create() {
  ::create();

  set_category("Movement");
  set_help_text(
    "Usage: go <direction> or go <filename>\n"
    "Move in a direction or to a specific destination file.\n"
    "Common directions include north, south, east, west, up, and down.\n"
  );
}

int main(string arg) {
  object player, location;
  mapping directions, exits;
  string direction, destination, filename;
  int moved;

  player = this_player();

  if (!objectp(player))
    return 0;

  if (!stringp(arg))
    return 0;

  arg = trim(arg);

  if (arg == "")
    return 0;

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

  direction = directions[arg];

  if (!stringp(direction))
    direction = arg;

  location = environment(player);

  if (objectp(location) && function_exists("dest_dir", location)) {
    exits = location->dest_dir();

    if (mapp(exits))
      destination = exits[direction];
  }

  if (stringp(destination)) {
    if (destination[0] != '/')
      destination = "/" + destination;

    moved = player->move(destination);

    return moved;
  }

  filename = arg;

  if (filename[0] != '/')
    filename = "/" + filename;

  if (file_size(filename + ".c") < 0)
    return 0;

  moved = player->move(filename);

  return moved;
}
