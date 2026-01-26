#include "room.h"

string short_desc, long_desc;
mapping dest_dir, exit_aliases;

void create() {
  short_desc = "";
  long_desc = "";
  dest_dir = ([]);
  exit_aliases = ([]);

  set_light(1);

  return;
}

void init() {
  string *dirs, *aliases;
  int i;

  dirs = keys(dest_dir);
  aliases = keys(exit_aliases);

  i = 0;

  while (i < sizeof(dirs)) {
    add_action("move", dirs[i]);

    i += 1;
  }

  i = 0;

  while (i < sizeof(aliases)) {
    add_action("move_alias", aliases[i]);

    i += 1;
  }

  return;
}

string short() {
  return short_desc;
}

string long(string str) {
  string description, exit_line;
  string *exits;

  description = long_desc;

  if (!mapp(dest_dir))
    return description;

  exits = keys(dest_dir);

  if (!sizeof(exits))
    return description;

  exit_line = "Exits: " + implode(exits, ", ") + ".";

  if (description == "")
    return exit_line;

  return description + "\n" + exit_line;
}

mapping dest_dir() {
  return dest_dir;
}

mapping exit_aliases() {
  return exit_aliases;
}

void add_exit_alias(string alias, string direction) {
  if (!exit_aliases)
    exit_aliases = ([]);

  exit_aliases[alias] = direction;

  return;
}

int move(string str) {
  string direction;

  direction = query_verb();

  return move_direction(direction);
}

int move_alias(string str) {
  string alias, canonical;

  alias = query_verb();

  if (!exit_aliases) return 0;

  canonical = exit_aliases[alias];

  if (!canonical) return 0;

  return move_direction(canonical);
}

int move_direction(string direction) {
  string destination;

  if (!mapp(dest_dir))
    return 0;

  destination = dest_dir[direction];

  if (!stringp(destination))
    return 0;

  if (destination[0] != '/')
    destination = "/" + destination;

  this_player()->move_player(direction + "#" + destination);

  return 1;
}
