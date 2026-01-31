inherit "/core/object";

#include "room.h"
#include <room-checks.c>

string short_desc, long_desc;
mapping exits;

void create() {
  ::create();

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

void add_exit(string use_word, string destination) {
  object exit;
  string resolved, base;
  string *parts;
  int last;

  if (!stringp(use_word))
    return;

  if (!stringp(destination))
    return;

  resolved = destination;

  if (destination[0] != '/') {
    base = base_name(this_object());
    parts = explode(base, "/");

    if (pointerp(parts) && sizeof(parts) > 1) {
      last = sizeof(parts) - 1;
      parts = parts[0..last - 1];
      resolved = "/" + implode(parts, "/") + "/" + destination;
    } else
      resolved = "/" + destination;
  }

  exit = new("/core/exit");

  exit->set_use_word(use_word);
  exit->set_destination(resolved);

  exits[use_word] = exit;

  return;
}

int has_exit(string use_word) {
  return is_member(keys(exits), use_word);
}

void use_exit(string use_word) {
  object exit;

  if (!has_exit(use_word)) {
    write("You can't go that way.\n");

    return;
  }

  exit = exits[use_word];

  if (!objectp(exit)) {
    write("You can't go that way.\n");

    return;
  }

  exit->use();

  return;
}
