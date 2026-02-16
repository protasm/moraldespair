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
 *   - #include <globals.h>
 */

#include "/core/daemon/move_d.h"
#include "/core/link/link.h"
#include <globals.h>

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
 *   - object actor, object origin, string direction
 * Approach:
 *   Validates inputs and executes explicit local logic for announce_departure.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from announce_departure.
 */
void announce_departure(object actor, object origin, string direction) {
  if (!objectp(actor) || !objectp(origin))
    return;

  EXPERIENCE_D->emit_movement_departure(actor, origin, direction);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles announce_arrival for this object.
 * Parameters:
 *   - object actor, object destination, string direction
 * Approach:
 *   Validates inputs and executes explicit local logic for announce_arrival.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from announce_arrival.
 */
void announce_arrival(object actor, object destination, string direction) {
  if (!objectp(actor) || !objectp(destination))
    return;

  EXPERIENCE_D->emit_movement_arrival(actor, destination, direction);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles announce_transition for this object.
 * Parameters:
 *   - object actor, object origin, object destination, object link,
 *     string departure_direction
 * Approach:
 *   Centralizes departure and arrival messaging for successful movement.
 * Side effects:
 *   Sends movement text to nearby connected avatars.
 * Returns:
 *   void result from announce_transition.
 */
void announce_transition(
  object actor,
  object origin,
  object destination,
  object link,
  string departure_direction
) {
  string arrival_direction;

  if (!objectp(actor) || !objectp(origin) || !objectp(destination))
    return;

  if (origin == destination)
    return;

  if (!stringp(departure_direction) || departure_direction == "")
    departure_direction = direction_for_link_from_room(origin, link);

  announce_departure(actor, origin, departure_direction);

  arrival_direction = direction_for_link_from_room(destination, link);
  announce_arrival(actor, destination, arrival_direction);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles combat_amount_from_mutation for this object.
 * Parameters:
 *   - mapping mutation
 * Approach:
 *   Extracts normalized combat impact amount from one mutation payload.
 * Side effects:
 *   None.
 * Returns:
 *   int result from combat_amount_from_mutation.
 */
int combat_amount_from_mutation(mapping mutation) {
  int amount;

  if (!mapp(mutation))
    return 0;

  amount = mutation["amount"];

  if (!intp(amount))
    amount = mutation["damage"];

  if (!intp(amount))
    amount = 0;

  if (amount < 0)
    amount = 0;

  return amount;
}

/* Method Summary:
 * Purpose:
 *   Handles emit_combat_events_from_mutations for this object.
 * Parameters:
 *   - object actor, object room, mixed mutations
 * Approach:
 *   Translates link mutation payloads into canonical combat-impact events.
 * Side effects:
 *   Emits combat experience to observers when damage-like mutations exist.
 * Returns:
 *   void result from emit_combat_events_from_mutations.
 */
void emit_combat_events_from_mutations(
  object actor,
  object room,
  mixed mutations
) {
  mapping mutation;
  mapping mutation_map;
  mixed payload;
  string mutation_type;
  int amount;
  int i;

  if (!objectp(actor) || !objectp(room))
    return;

  if (pointerp(mutations)) {
    for (i = 0; i < sizeof(mutations); i++) {
      mutation = mutations[i];

      if (!mapp(mutation))
        continue;

      mutation_type = mutation["type"];

      if (!stringp(mutation_type))
        continue;

      mutation_type = lower_case(trim(mutation_type));

      if (mutation_type != "damage" && mutation_type != "combat")
        continue;

      amount = combat_amount_from_mutation(mutation);
      EXPERIENCE_D->emit_combat_impact(actor, actor, room, "suffers impact from", amount);
    }

    return;
  }

  if (!mapp(mutations))
    return;

  mutation_map = mutations;

  if (!undefinedp(mutation_map["damage"])) {
    payload = mutation_map["damage"];

    if (mapp(payload))
      amount = combat_amount_from_mutation(payload);
    else if (intp(payload))
      amount = payload;
    else
      amount = 0;

    if (amount < 0)
      amount = 0;

    EXPERIENCE_D->emit_combat_impact(actor, actor, room, "is struck for", amount);
    return;
  }

  if (!undefinedp(mutation_map["combat"])) {
    payload = mutation_map["combat"];

    if (mapp(payload))
      amount = combat_amount_from_mutation(payload);
    else if (intp(payload))
      amount = payload;
    else
      amount = 0;

    if (amount < 0)
      amount = 0;

    EXPERIENCE_D->emit_combat_impact(actor, actor, room, "is hit for", amount);
  }

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles try_move_label for this object.
 * Parameters:
 *   - object avatar, string label
 * Approach:
 *   Validates inputs and executes explicit local logic for try_move_label.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   object result from try_move_label.
 */
object try_move_label(object avatar, string label) {
  object origin, link;
  object destination;
  mapping exits, result;
  string msg;
  mapping direction_aliases;
  int is_direction;

  if (!objectp(avatar))
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

  origin = environment(avatar);

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
      avatar_experience(avatar, "You can't go " + label + " from here.\n");

    return 0;
  }

  link = exits[label];

  /* THE ONE TRUE MOVE */
  result = link->traverse(avatar, origin);

  if (!mapp(result))
    return 0;

  emit_combat_events_from_mutations(
    avatar,
    origin,
    result[LINK_RESULT_MUTATIONS]
  );

  if (!link->is_allowed_result(result)) {
    msg = result[LINK_RESULT_MESSAGE];

    if (!stringp(msg) || msg == "")
      msg = "You cannot go that way.\n";
    else if (msg[<1] != '\n')
      msg += "\n";

    avatar_experience(avatar, msg);

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
  destination = environment(avatar);

  if (objectp(destination) && destination != origin) {
    announce_transition(avatar, origin, destination, link, label);
  }

  return destination;
}

/* Method Summary:
 * Purpose:
 *   Handles try_move for this object.
 * Parameters:
 *   - object avatar, string direction
 * Approach:
 *   Validates inputs and executes explicit local logic for try_move.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   object result from try_move.
 */
object try_move(object avatar, string direction) {
  return try_move_label(avatar, direction);
}
