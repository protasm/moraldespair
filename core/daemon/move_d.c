#include "/core/daemon/move_d.h"
#include "/core/link/link.h"

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

object try_move_label(object player, string label) {
  object origin, link;
  mapping exits, result;
  string msg;
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

  return environment(player);
}

object try_move(object player, string direction) {
  return try_move_label(player, direction);
}
