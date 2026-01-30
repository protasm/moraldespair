#include "room.h"

string short_desc, long_desc;
mapping exits;

void create() {
  short_desc = "";
  long_desc = "";
  exits = ([]);

  set_light(1);

  return;
}

string short() {
  return short_desc;
}

string long() {
  string exit_line;
  string *dirs;

  dirs = keys(exits);

  if (!sizeof(dirs))
    return long_desc;

  exit_line = "Exits: " + implode(dirs, ", ") + ".";

  return long_desc + "\n\n" + exit_line;
}

mapping exits() {
  return exits;
}

int has_exit(string str) {
  return is_member(keys(exits), str);
}

int get_exit_dest(string dir) {
  return exits[dir];
}
