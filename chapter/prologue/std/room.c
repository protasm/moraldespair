inherit "/core/object";

#include "room.h"

string short_desc, long_desc;
object room_link_cache;

void create() {
  ::create();

  short_desc = "";
  long_desc = "";
  room_link_cache = 0;

  set_light(1);

  room_link_cache = new("/core/link_cache");

  if (objectp(room_link_cache))
    room_link_cache->init_for_room(this_object());

  return;
}

string short() {
  return short_desc;
}

string long() {
  return long_desc;
}

object link_cache() {
  return room_link_cache;
}

/*
 * Pre- and Post- Movement and Action Hooks
 */
int pre_leave(object exit) {
  return 1;
}

void post_leave(object exit) {
  return;
}

int pre_arrive(object exit) {
  return 1;
}

void post_arrive(object exit) {
}

int pre_action(object action) {
  return 1;
}

void post_action(object action) {
  return;
}

/*
 * Link Handling
 */

/* Link affordances: label -> Link object */
mapping _links;

/*
 * Register a Link affordance for this room.
 * This does NOT define topology.
 */
void add_link(string label, object link) {
  object existing;

  if (!stringp(label) || !objectp(link))
    return;

  if (!mapp(_links))
    _links = ([]);

  existing = _links[label];

  if (objectp(existing) && existing != link) {
    write(
      "ROOM: Link label collision for " + base_name(this_object()) + ".\n" +
      "  Label '" + label + "' already assigned.\n"
    );

    return;
  }

  _links[label] = link;
}

/*
 * Resolve a Link by label (used by movement commands).
 */
object link(string label) {
  if (!mapp(_links))
    return 0;

  return _links[label];
}

/*
 * Optional: expose available directions for display/debugging.
 */
string *link_labels() {
  if (!mapp(_links))
    return ({ });

  return keys(_links);
}
