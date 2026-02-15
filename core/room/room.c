inherit "/core/object/object";

#include "room.h"
#include "/core/link/link.h"

string short_desc, long_desc;
object room_link_cache;

void create() {
  ::create();

  short_desc = "";
  long_desc = "";
  room_link_cache = 0;

  set_light(1);

  room_link_cache = new("/core/link/link_cache");

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

mapping terrain_room_data() {
  object room_data_daemon;
  mapping room_details;
  string lookup_path;

  lookup_path = base_name(this_object());

  if (function_exists("link_endpoint_id", this_object())) {
    lookup_path = this_object()->link_endpoint_id();

    if (!stringp(lookup_path) || lookup_path == "")
      lookup_path = base_name(this_object());
  }

  room_data_daemon = find_object("/core/daemon/room_data_d");

  if (!objectp(room_data_daemon))
    room_data_daemon = load_object("/core/daemon/room_data_d");

  room_details = 0;

  if (objectp(room_data_daemon))
    room_details = room_data_daemon->room_data(lookup_path);

  if (!mapp(room_details))
    return 0;

  return room_details;
}

mapping link_can_enter(object actor, object link) {
  mapping room_details;
  string traverse_failure;
  string blocked_message;
  int traverse_cost;

  if (!objectp(actor))
    return ([ LINK_RESULT_OUTCOME : LINK_OUTCOME_ALLOW ]);

  if (wizardp(actor))
    return ([ LINK_RESULT_OUTCOME : LINK_OUTCOME_ALLOW ]);

  if (function_exists("is_wizard", actor)) {
    if (actor->is_wizard())
      return ([ LINK_RESULT_OUTCOME : LINK_OUTCOME_ALLOW ]);
  } else if (!userp(actor))
    return ([ LINK_RESULT_OUTCOME : LINK_OUTCOME_ALLOW ]);

  room_details = terrain_room_data();

  if (!mapp(room_details))
    return ([ LINK_RESULT_OUTCOME : LINK_OUTCOME_ALLOW ]);

  traverse_cost = room_details["traverse_cost"];

  if (!intp(traverse_cost))
    traverse_cost = 0;

  if (traverse_cost >= 0)
    return ([ LINK_RESULT_OUTCOME : LINK_OUTCOME_ALLOW ]);

  traverse_failure = room_details["traverse_failure"];

  if (stringp(traverse_failure) && traverse_failure != "")
    blocked_message = traverse_failure;
  else
    blocked_message = "That terrain is not passable right now.";

  return ([
    LINK_RESULT_OUTCOME : LINK_OUTCOME_DENY,
    LINK_RESULT_MESSAGE : blocked_message,
    LINK_RESULT_REDIRECT : "",
    LINK_RESULT_COST : 0,
    LINK_RESULT_MUTATIONS : ({ })
  ]);
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
