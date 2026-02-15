/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/room/room.c.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - inherit "/core/object/object";
 *   - #include "room.h"
 *   - #include "/core/link/link.h"
 */

inherit "/core/object/object";

#include "room.h"
#include "/core/link/link.h"

string short_desc, long_desc;
object room_link_cache;

/* Method Summary:
 * Purpose:
 *   Handles create for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for create.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from create.
 */
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

/* Method Summary:
 * Purpose:
 *   Handles room_id_value for this object.
 * Parameters:
 *   - mapping room_details
 * Approach:
 *   Validates inputs and executes explicit local logic for room_id_value.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from room_id_value.
 */
string room_id_value(mapping room_details) {
  string room_id;

  room_id = "";

  if (mapp(room_details))
    room_id = room_details["id"];

  if (stringp(room_id) && room_id != "")
    return room_id;

  if (function_exists("room_id", this_object()))
    room_id = this_object()->room_id();

  if (!stringp(room_id) || room_id == "")
    return "";

  return room_id;
}

/* Method Summary:
 * Purpose:
 *   Handles terrain_long_value for this object.
 * Parameters:
 *   - mapping room_details
 * Approach:
 *   Validates inputs and executes explicit local logic for terrain_long_value.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from terrain_long_value.
 */
string terrain_long_value(mapping room_details) {
  mixed long_value;
  string *long_options;
  int long_index;

  if (!mapp(room_details))
    return "";

  long_value = room_details["long"];

  if (stringp(long_value) && long_value != "")
    return long_value;

  if (!pointerp(long_value))
    return "";

  long_options = long_value;

  if (!sizeof(long_options))
    return "";

  long_index = random(sizeof(long_options));
  long_value = long_options[long_index];

  if (!stringp(long_value) || long_value == "")
    return "";

  return long_value;
}

/* Method Summary:
 * Purpose:
 *   Handles short for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for short.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from short.
 */
string short() {
  mapping room_details;
  string terrain_short;
  string room_id;

  if (stringp(short_desc) && short_desc != "")
    return short_desc;

  room_details = terrain_room_data();
  terrain_short = "";

  if (mapp(room_details))
    terrain_short = room_details["short"];

  if (stringp(terrain_short) && terrain_short != "")
    short_desc = terrain_short;

  if (stringp(short_desc) && short_desc != "")
    return short_desc;

  room_id = room_id_value(room_details);

  if (stringp(room_id) && room_id != "")
    short_desc = room_id;

  if (stringp(short_desc) && short_desc != "")
    return short_desc;

  return "Undefined";
}

/* Method Summary:
 * Purpose:
 *   Handles long for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for long.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from long.
 */
string long() {
  mapping room_details;
  string terrain_long;

  if (stringp(long_desc) && long_desc != "")
    return long_desc;

  room_details = terrain_room_data();
  terrain_long = terrain_long_value(room_details);

  if (stringp(terrain_long) && terrain_long != "")
    long_desc = terrain_long;

  if (stringp(long_desc) && long_desc != "")
    return long_desc;

  return "Undefined";
}

/* Method Summary:
 * Purpose:
 *   Handles link_cache for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for link_cache.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   object result from link_cache.
 */
object link_cache() {
  return room_link_cache;
}

/*
 * Pre- and Post- Movement and Action Hooks
 */
/* Method Summary:
 * Purpose:
 *   Handles pre_leave for this object.
 * Parameters:
 *   - object exit
 * Approach:
 *   Validates inputs and executes explicit local logic for pre_leave.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from pre_leave.
 */
int pre_leave(object exit) {
  return 1;
}

/* Method Summary:
 * Purpose:
 *   Handles post_leave for this object.
 * Parameters:
 *   - object exit
 * Approach:
 *   Validates inputs and executes explicit local logic for post_leave.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from post_leave.
 */
void post_leave(object exit) {
  return;
}

/* Method Summary:
 * Purpose:
 *   Handles pre_arrive for this object.
 * Parameters:
 *   - object exit
 * Approach:
 *   Validates inputs and executes explicit local logic for pre_arrive.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from pre_arrive.
 */
int pre_arrive(object exit) {
  return 1;
}

/* Method Summary:
 * Purpose:
 *   Handles post_arrive for this object.
 * Parameters:
 *   - object exit
 * Approach:
 *   Validates inputs and executes explicit local logic for post_arrive.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from post_arrive.
 */
void post_arrive(object exit) {
}

/* Method Summary:
 * Purpose:
 *   Handles pre_action for this object.
 * Parameters:
 *   - object action
 * Approach:
 *   Validates inputs and executes explicit local logic for pre_action.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from pre_action.
 */
int pre_action(object action) {
  return 1;
}

/* Method Summary:
 * Purpose:
 *   Handles post_action for this object.
 * Parameters:
 *   - object action
 * Approach:
 *   Validates inputs and executes explicit local logic for post_action.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from post_action.
 */
void post_action(object action) {
  return;
}

/* Method Summary:
 * Purpose:
 *   Handles terrain_room_data for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for terrain_room_data.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   mapping result from terrain_room_data.
 */
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

/* Method Summary:
 * Purpose:
 *   Handles link_can_enter for this object.
 * Parameters:
 *   - object actor, object link
 * Approach:
 *   Validates inputs and executes explicit local logic for link_can_enter.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   mapping result from link_can_enter.
 */
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
/* Method Summary:
 * Purpose:
 *   Handles add_link for this object.
 * Parameters:
 *   - string label, object link
 * Approach:
 *   Validates inputs and executes explicit local logic for add_link.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from add_link.
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
/* Method Summary:
 * Purpose:
 *   Handles link for this object.
 * Parameters:
 *   - string label
 * Approach:
 *   Validates inputs and executes explicit local logic for link.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   object result from link.
 */
object link(string label) {
  if (!mapp(_links))
    return 0;

  return _links[label];
}

/*
 * Optional: expose available directions for display/debugging.
 */
/* Method Summary:
 * Purpose:
 *   Handles link_labels for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for link_labels.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from link_labels.
 */
string *link_labels() {
  if (!mapp(_links))
    return ({ });

  return keys(_links);
}
