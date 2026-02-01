/*
 * MOVE_D
 *
 * Central movement handler.
 *
 * - Resolves directional movement via LINK_D
 * - Delegates permission checks to Link objects
 * - Performs the actual environment change
 */

object try_move(object player, string direction) {
  object env, link;
  mapping exits;
  string from_room, to_room;

  if (!objectp(player))
    return 0;

  env = environment(player);
  if (!objectp(env))
    return 0;

  from_room = base_name(env);

  direction = trim(direction);
  if (direction == "")
    return 0;

  /*
   * Ask LINK_D: what links are visible from here, keyed by direction?
   */
  exits = LINK_D->links_by_direction_for_room(from_room);

  if (!mapp(exits) || !exits[direction]) {
    tell_object(player, "You can't go that way.\n");
    return 0;
  }

  link = exits[direction];
  if (!objectp(link)) {
    tell_object(player, "Something feels wrong with that path.\n");
    return 0;
  }

  /*
   * Permission / gating
   */
  if (function_exists("can_traverse", link)) {
    if (!link->can_traverse(player, from_room)) {
      string msg;

      if (function_exists("query_fail_msg", link))
        msg = link->query_fail_msg(player, from_room);

      if (!stringp(msg) || msg == "")
        msg = "You cannot go that way.\n";

      tell_object(player, msg);
      return 0;
    }
  }

  /*
   * Resolve destination
   */
  if (!function_exists("query_other_side", link)) {
    tell_object(player, "The way forward is unclear.\n");
    return 0;
  }

  to_room = link->query_other_side(from_room);
  if (!stringp(to_room) || to_room == "") {
    tell_object(player, "You cannot go that way.\n");
    return 0;
  }

  /*
   * Pre-traverse hook
   */
  if (function_exists("on_traverse", link))
    link->on_traverse(player, from_room);

  /*
   * Perform the move
   */
  player->move(to_room);

  /*
   * Optional post-move hook
   */
  if (function_exists("on_arrive", link))
    link->on_arrive(player, to_room);

  return environment(player);
}

