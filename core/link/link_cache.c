/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/link/link_cache.c.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - inherit "/core/object/object";
 *   - #include <globals.h>
 *   - #include "link_cache.h"
 */

inherit "/core/object/object";

#include <globals.h>

#include "link_cache.h"

object cached_room;
string cached_endpoint_id;
object *links;
mapping links_by_direction;

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

/*
 * void create()
 * Initialize the cache state with empty room and link data.
 * Inputs: none.
 * Outputs: none.
 */
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

  // No room is bound until init_for_room is called.
  cached_room = 0;

  // Endpoint id is the base_name of the bound room.
  cached_endpoint_id = "";

  // Cached link list and direction mapping start empty.
  links = ({ });
  links_by_direction = ([ ]);

  return;
}

/*
 * void init_for_room(object target)
 * Bind this cache to a room object and populate initial link data.
 * Inputs: target (room object).
 * Outputs: none.
 */
/* Method Summary:
 * Purpose:
 *   Handles init_for_room for this object.
 * Parameters:
 *   - object target
 * Approach:
 *   Validates inputs and executes explicit local logic for init_for_room.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from init_for_room.
 */
void init_for_room(object target) {
  // Guard against invalid room objects.
  if (!objectp(target))
    return;

  // Store the room and its endpoint id for link lookups.
  cached_room = target;
  cached_endpoint_id = endpoint_id_for_room(target);

  // Build the initial link cache for this room.
  refresh_links();

  return;
}

/*
 * void refresh_links()
 * Query LINK_D for links touching the cached endpoint and store them locally.
 * Inputs: none.
 * Outputs: none.
 */
/* Method Summary:
 * Purpose:
 *   Handles refresh_links for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for refresh_links.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from refresh_links.
 */
void refresh_links() {
  // If no endpoint is set, reset cached data.
  if (!stringp(cached_endpoint_id) || cached_endpoint_id == "") {
    links = ({ });
    links_by_direction = ([ ]);

    return;
  }

  // Get all links that touch this endpoint.
  links = LINK_D->links_for_room(cached_endpoint_id);

  // Normalize missing or invalid results.
  if (!pointerp(links))
    links = ({ });

  // Build direction -> link mapping for direction disambiguation.
  links_by_direction = LINK_D->links_by_direction_for_room(cached_endpoint_id);

  // Normalize missing or invalid results.
  if (!mapp(links_by_direction))
    links_by_direction = ([ ]);

  return;
}

/*
 * object room()
 * Return the room object this cache is bound to.
 * Inputs: none.
 * Outputs: room object or 0.
 */
/* Method Summary:
 * Purpose:
 *   Handles room for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for room.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   object result from room.
 */
object room() {
  return cached_room;
}

/*
 * string endpoint_id()
 * Return the base_name id of the bound room.
 * Inputs: none.
 * Outputs: endpoint id string or "".
 */
/* Method Summary:
 * Purpose:
 *   Handles endpoint_id for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for endpoint_id.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from endpoint_id.
 */
string endpoint_id() {
  return cached_endpoint_id;
}

/*
 * int handle_input(object actor, string verb, string arg)
 * Attempt to match player input against cached links and handle it.
 * Inputs:
 *   actor - the player object issuing the command.
 *   verb  - the normalized verb string.
 *   arg   - the remaining argument string.
 * Outputs:
 *   1 if a link handled the input (or a disambiguation prompt was shown),
 *   0 if the cache did not handle the input.
 */
/* Method Summary:
 * Purpose:
 *   Handles handle_input for this object.
 * Parameters:
 *   - object actor, string verb, string arg
 * Approach:
 *   Validates inputs and executes explicit local logic for handle_input.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from handle_input.
 */
int handle_input(object actor, string verb, string arg) {
  object *matches;
  object *active_links;
  mapping match;
  mapping entry;
  object link;
  string direction;
  string remainder;
  string example_dir;
  string gate_name;
  int i;
  int handled;

  // Only handle input when we have a valid actor and endpoint.
  if (!objectp(actor))
    return 0;

  if (!stringp(verb) || verb == "")
    return 0;

  if (!stringp(cached_endpoint_id) || cached_endpoint_id == "")
    return 0;

  // No cached links means nothing to handle.
  if (!pointerp(links) || !sizeof(links))
    return 0;

  // Normalize argument to a string for parsing.
  if (!stringp(arg))
    arg = "";

  // Start with all cached links and refine if needed.
  matches = ({ });
  active_links = links;

  // If arguments exist, try a leading direction hint first.
  if (arg != "") {
    direction = "";
    remainder = "";

    // Split the first token to see if it looks like a direction.
    if (sscanf(arg, "%s %s", direction, remainder) != 2) {
      direction = arg;
      remainder = "";
    }

    // Normalize the direction token before lookup.
    direction = lower_case(direction);

    // When the direction maps to a single link, narrow to it.
    if (mapp(links_by_direction) && objectp(links_by_direction[direction])) {
      active_links = ({ links_by_direction[direction] });
      arg = remainder;
    }
  }

  // Ask each candidate link whether it matches this verb + arg.
  for (i = 0; i < sizeof(active_links); i++) {
    link = active_links[i];

    if (!objectp(link))
      continue;

    if (function_exists("action_match", link)) {
      match = link->action_match(actor, verb, arg, cached_endpoint_id);

      if (mapp(match) && match["matched"])
        matches += ({ ([ "link" : link, "match" : match ]) });
    }
  }

  // A single match means we can hand off directly to the link.
  if (pointerp(matches) && sizeof(matches) == 1) {
    entry = (mapping)matches[0];
    link = entry["link"];

    if (objectp(link) && function_exists("handle_action", link)) {
      handled = link->handle_action(actor, verb, arg, cached_endpoint_id);

      if (handled)
        return 1;
    }
  }

  // Multiple matches require disambiguation by direction.
  if (pointerp(matches) && sizeof(matches) > 1) {
    example_dir = "";
    gate_name = "";

    // Use the first match for a name hint, if available.
    entry = (mapping)matches[0];
    match = entry["match"];

    if (mapp(match) && stringp(match["name"]))
      gate_name = match["name"];

    // Find a direction label to help the player clarify.
    for (i = 0; i < sizeof(matches); i++) {
      entry = (mapping)matches[i];
      link = entry["link"];

      if (!objectp(link))
        continue;

      if (function_exists("direction_label", link))
        example_dir = link->direction_label(cached_endpoint_id);

      if (stringp(example_dir) && example_dir != "")
        break;
    }

    // Provide a targeted prompt to resolve the ambiguity.
    if (stringp(example_dir) && example_dir != "") {
      if (stringp(gate_name) && gate_name != "")
        write(
          "Please specify a direction; for example, '" +
          example_dir + " " + gate_name + "'.\n"
        );
      else
        write(
          "Please specify a direction; for example, '" +
          example_dir + "'.\n"
        );
    } else {
      write("Please specify a direction.\n");
    }

    return 1;
  }

  // No link matched the input.
  return 0;
}
