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

object add_exit_object(object exit, string use_word, string destination) {
  string resolved, base;
  string *parts;
  int last;

  if (!objectp(exit))
    return 0;

  if (!stringp(use_word))
    return 0;

  if (!stringp(destination))
    return 0;

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

  exit->set_use_word(use_word);
  exit->set_destination(resolved);
  exit->set_origin(this_object());

  exits[use_word] = exit;

  return exit;
}

object add_exit(string use_word, string destination) {
  object exit;
  string resolved, base;
  string *parts;
  int last;

  if (!stringp(use_word))
    return 0;

  if (!stringp(destination))
    return 0;

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
  exit->set_origin(this_object());

  exits[use_word] = exit;

  return exit;
}

int has_exit(string use_word) {
  return is_member(keys(exits), use_word);
}

object exit_for(string use_word) {
  if (!has_exit(use_word))
    return 0;

  return exits[use_word];
}

int try_exit(string use_word) {
  object exit;

  exit = exit_for(use_word);

  if (!objectp(exit))
    return 0;

  exit->use();

  return 1;
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
