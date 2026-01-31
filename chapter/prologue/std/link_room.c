inherit "/chapter/prologue/std/room";

#include <globals.h>

mapping links;

void create() {
  ::create();

  links = ([]);

  return;
}

string resolve_link_destination(string destination) {
  string resolved, base;
  string *parts;
  int last;

  if (!stringp(destination))
    return "";

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

  return resolved;
}

object add_link(string direction, string destination) {
  object link;
  string resolved;
  string origin_id;

  if (!stringp(direction))
    return 0;

  resolved = resolve_link_destination(destination);

  if (resolved == "")
    return 0;

  origin_id = base_name(this_object());
  link = LINK_D->get_link(origin_id, resolved);

  if (!objectp(link))
    return 0;

  link->set_direction_label(origin_id, direction);
  links[direction] = link;

  return link;
}

object link_for(string direction) {
  if (!stringp(direction))
    return 0;

  return links[direction];
}

string *link_directions() {
  if (!mapp(links))
    return ({ });

  return keys(links);
}

string long() {
  string exit_line;
  string *dirs;
  string *exit_dirs;
  string *link_dirs;
  int i;

  dirs = ({ });
  exit_dirs = keys(exits());
  link_dirs = link_directions();

  for (i = 0; i < sizeof(exit_dirs); i++) {
    if (member_array(exit_dirs[i], dirs) == -1)
      dirs += ({ exit_dirs[i] });
  }

  for (i = 0; i < sizeof(link_dirs); i++) {
    if (member_array(link_dirs[i], dirs) == -1)
      dirs += ({ link_dirs[i] });
  }

  if (!sizeof(dirs))
    return long_desc;

  exit_line = "Exits: " + implode(dirs, ", ") + ".";

  return long_desc + "\n\n" + exit_line;
}
