/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/daemon/move_d.c.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - #include "/core/daemon/move_d.h"
 *   - #include "/core/link/link.h"
 */

#include "/core/daemon/move_d.h"
#include "/core/link/link.h"

/* Method Summary:
 * Purpose:
 *   Handles endpoint_id_for_room for this object.
 * Parameters:
 *   - object room
 * Approach:
 *   Validates inputs and executes explicit local logic for endpoint_id_for_room.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from endpoint_id_for_room.
 */
string endpoint_id_for_room(object room) {
  string endpoint_id;

  endpoint_id = "";

  if (!objectp(room))
    return endpoint_id;

  if (function_exists("link_endpoint_id", room))
    endpoint_id = room->link_endpoint_id();

  if (!stringp(endpoint_id) || endpoint_id == "")
    endpoint_id = base_name(room);

  return endpoint_id;
}

/* Method Summary:
 * Purpose:
 *   Handles actor_name_for_message for this object.
 * Parameters:
 *   - object actor
 * Approach:
 *   Validates inputs and executes explicit local logic for actor_name_for_message.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from actor_name_for_message.
 */
string actor_name_for_message(object actor) {
  string actor_name;

  actor_name = "";

  if (!objectp(actor))
    return "Someone";

  if (function_exists("name", actor))
    actor_name = actor->name();

  if (!stringp(actor_name) || actor_name == "")
    actor_name = "Someone";

  return actor_name;
}

/* Method Summary:
 * Purpose:
 *   Handles direction_for_link_from_room for this object.
 * Parameters:
 *   - object room, object link
 * Approach:
 *   Validates inputs and executes explicit local logic for direction_for_link_from_room.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from direction_for_link_from_room.
 */
string direction_for_link_from_room(object room, object link) {
  mapping exits;
  string room_id;
  string *dirs;
  int i;

  if (!objectp(room) || !objectp(link))
    return "";

  room_id = endpoint_id_for_room(room);

  if (!stringp(room_id) || room_id == "")
    return "";

  exits = LINK_D->links_by_direction_for_room(room_id);

  if (!mapp(exits) || !sizeof(exits))
    return "";

  dirs = keys(exits);

  for (i = 0; i < sizeof(dirs); i++) {
    if (objectp(exits[dirs[i]]) && exits[dirs[i]] == link)
      return dirs[i];
  }

  return "";
}

/* Method Summary:
 * Purpose:
 *   Handles announce_departure for this object.
 * Parameters:
 *   - object player, object origin, string direction
 * Approach:
 *   Validates inputs and executes explicit local logic for announce_departure.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from announce_departure.
 */
void announce_departure(object player, object origin, string direction) {
  string actor_name;
  string line;
  object *listeners;
  object listener;
  int i;

  if (!objectp(player) || !objectp(origin))
    return;

  if (!userp(player))
    return;

  actor_name = actor_name_for_message(player);

  if (stringp(direction) && direction != "")
    line = actor_name + " leaves " + direction + ".\n";
  else
    line = actor_name + " leaves.\n";

  listeners = all_inventory(origin);

  if (!pointerp(listeners) || !sizeof(listeners))
    return;

  for (i = 0; i < sizeof(listeners); i++) {
    listener = listeners[i];

    if (!objectp(listener) || listener == player)
      continue;

    if (!userp(listener))
      continue;

    tell_object(listener, line);
  }

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles announce_arrival for this object.
 * Parameters:
 *   - object player, object destination, string direction
 * Approach:
 *   Validates inputs and executes explicit local logic for announce_arrival.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from announce_arrival.
 */
void announce_arrival(object player, object destination, string direction) {
  string actor_name;
  string line;
  object *listeners;
  object listener;
  int i;

  if (!objectp(player) || !objectp(destination))
    return;

  if (!userp(player))
    return;

  actor_name = actor_name_for_message(player);

  if (stringp(direction) && direction != "")
    line = actor_name + " arrives from " + direction + ".\n";
  else
    line = actor_name + " arrives.\n";

  listeners = all_inventory(destination);

  if (!pointerp(listeners) || !sizeof(listeners))
    return;

  for (i = 0; i < sizeof(listeners); i++) {
    listener = listeners[i];

    if (!objectp(listener) || listener == player)
      continue;

    if (!userp(listener))
      continue;

    tell_object(listener, line);
  }

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles try_move_label for this object.
 * Parameters:
 *   - object player, string label
 * Approach:
 *   Validates inputs and executes explicit local logic for try_move_label.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   object result from try_move_label.
 */
object try_move_label(object player, string label) {
  object origin, link;
  object destination;
  mapping exits, result;
  string msg;
  string arrival_direction;
  mapping direction_aliases;
  int is_direction;

  if (!objectp(player))
    return 0;

  if (!stringp(label))
    label = "";

  label = lower_case(trim(label));

  if (label == "")
    return 0;

  direction_aliases = ([
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

  if (mapp(direction_aliases) && stringp(direction_aliases[label]))
    label = direction_aliases[label];

  origin = environment(player);

  if (!objectp(origin))
    return 0;

  exits = LINK_D->links_by_direction_for_room(endpoint_id_for_room(origin));

  if (!mapp(exits) || !objectp(exits[label])) {
    is_direction = (member_array(label, ({
      "north",
      "south",
      "east",
      "west",
      "northeast",
      "northwest",
      "southeast",
      "southwest",
      "up",
      "down",
      "in",
      "out"
    })) != -1);

    if (is_direction)
      write("You can't go " + label + " from here.\n");

    return 0;
  }

  link = exits[label];

  /* THE ONE TRUE MOVE */
  result = link->traverse(player, origin);

  if (!mapp(result))
    return 0;

  if (!link->is_allowed_result(result)) {
    msg = result[LINK_RESULT_MESSAGE];

    if (!stringp(msg) || msg == "")
      msg = "You cannot go that way.\n";
    else if (msg[<1] != '\n')
      msg += "\n";

    write(msg);

    return 0;
  }

  /*
   * At this point:
   * - movement already happened
   * - reverse/redirect already handled
   * - cost/effects already accumulated
   *
   * MOVE_D does not second-guess outcomes.
   */
  destination = environment(player);

  if (objectp(destination) && destination != origin) {
    announce_departure(player, origin, label);

    arrival_direction = direction_for_link_from_room(destination, link);
    announce_arrival(player, destination, arrival_direction);
  }

  return destination;
}

/* Method Summary:
 * Purpose:
 *   Handles try_move for this object.
 * Parameters:
 *   - object player, string direction
 * Approach:
 *   Validates inputs and executes explicit local logic for try_move.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   object result from try_move.
 */
object try_move(object player, string direction) {
  return try_move_label(player, direction);
}
