object try_move(object player, string direction) {
  object origin, link;
  mapping exits, result;
  string msg;

  if (!objectp(player))
    return 0;

  origin = environment(player);

  if (!objectp(origin))
    return 0;

  exits = LINK_D->links_by_direction_for_room(base_name(origin));

  if (!mapp(exits) || !objectp(exits[direction])) {
    write("You can't go that way.\n");

    return 0;
  }

  link = exits[direction];

  /* THE ONE TRUE MOVE */
  result = link->traverse(player, origin);

  if (!mapp(result))
    return 0;

  if (!link->is_allowed_result(result)) {
    msg = result[LINK_RESULT_MESSAGE];

    if (!stringp(msg) || msg == "")
      msg = "You cannot go that way.\n";

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

