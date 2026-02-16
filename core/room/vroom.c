/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/room/vroom.c.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - inherit "/core/room/room";
 *   - #include "/core/link/link.h"
 *   - #include "vroom.h"
 */

#define ROOM_DATA_D "/core/daemon/room_data_d"

inherit "/core/room/room";

#include "/core/link/link.h"
#include "vroom.h"

string room_path;

/* Method Summary:
 * Purpose:
 *   Handles room_data for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for room_data.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   mapping result from room_data.
 */
mapping room_data() {
  object room_data_daemon;
  mapping room_details;

  if (!stringp(room_path) || room_path == "")
    return 0;

  room_data_daemon = find_object(ROOM_DATA_D);

  if (!objectp(room_data_daemon))
    room_data_daemon = load_object(ROOM_DATA_D);

  room_details = 0;

  if (objectp(room_data_daemon))
    room_details = room_data_daemon->room_data(room_path);

  if (!mapp(room_details))
    return 0;

  return room_details;
}

/* Method Summary:
 * Purpose:
 *   Handles set_descriptions for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for set_descriptions.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from set_descriptions.
 */
void set_descriptions() {
  mapping room_details;
  mixed long_data;
  string *long_options;
  string short_name, long_name;
  string terrain_short, terrain_long;
  int long_index;

  room_details = room_data();

  short_name = 0;
  long_name = 0;
  terrain_short = 0;
  terrain_long = 0;
  long_data = 0;
  long_options = ({ });
  long_index = 0;

  if (mapp(room_details)) {
    short_name = room_details["_explicit_short"];
    long_data = room_details["_explicit_long"];
    terrain_short = room_details["short"];
    terrain_long = terrain_long_value(room_details);

    if (pointerp(long_data)) {
      long_options = long_data;

      if (sizeof(long_options) > 0) {
        long_index = random(sizeof(long_options));
        long_name = long_options[long_index];
      }
    } else if (stringp(long_data))
      long_name = long_data;
  }

  if (stringp(short_name) && short_name != "")
    short_desc = short_name;
  else if (stringp(terrain_short) && terrain_short != "")
    short_desc = terrain_short;
  else
    short_desc = "";

  if (stringp(long_name) && long_name != "")
    long_desc = long_name;
  else if (stringp(terrain_long) && terrain_long != "")
    long_desc = terrain_long;
  else
    long_desc = "";

  return;
}

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

  if (stringp(room_path) && room_path != "")
    set_descriptions();

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles set_room_path for this object.
 * Parameters:
 *   - string path
 * Approach:
 *   Validates inputs and executes explicit local logic for set_room_path.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from set_room_path.
 */
void set_room_path(string path) {
  object cache;

  room_path = path;

  set_descriptions();
  ensure_room_npc_spawns();
  cache = link_cache();

  if (objectp(cache) && function_exists("init_for_room", cache))
    cache->init_for_room(this_object());

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles room_id for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for room_id.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from room_id.
 */
string room_id() {
  return room_path;
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
  string terrain_code;
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
  } else if (!is_connected_avatar(actor))
    return ([ LINK_RESULT_OUTCOME : LINK_OUTCOME_ALLOW ]);

  room_details = room_data();

  if (!mapp(room_details))
    room_details = ([]);

  terrain_code = room_details["terrain"];

  if (stringp(terrain_code) && lower_case(terrain_code) == "w") {
    traverse_failure = room_details["traverse_failure"];

    if (stringp(traverse_failure) && traverse_failure != "")
      blocked_message = traverse_failure;
    else
      blocked_message = "A body of open water blocks that direction.";

    return ([
      LINK_RESULT_OUTCOME : LINK_OUTCOME_DENY,
      LINK_RESULT_MESSAGE : blocked_message,
      LINK_RESULT_REDIRECT : "",
      LINK_RESULT_COST : 0,
      LINK_RESULT_MUTATIONS : ({ })
    ]);
  }

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

/* Method Summary:
 * Purpose:
 *   Handles link_endpoint_id for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for link_endpoint_id.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from link_endpoint_id.
 */
string link_endpoint_id() {
  if (!stringp(room_path) || room_path == "")
    return base_name(this_object());

  return room_path;
}
