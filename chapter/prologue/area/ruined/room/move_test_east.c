inherit "/chapter/prologue/std/room";

object west_exit;

void create() {
  ::create();

  short_desc = "Movement Testing Room";
  long_desc = "This is the Movement Testing Room to the east of the Players' Lounge.";

  west_exit = add_exit_object(
    new("/chapter/prologue/area/ruined/room/move_test_east_west_exit"),
    "west",
    "lounge"
  );
}

void post_arrive(object exit) {
  object player;

  if (!objectp(exit))
    return;

  if (exit->use_word() != "east")
    return;

  player = this_player();

  if (!objectp(player))
    return;

  player->move("/chapter/prologue/area/ruined/room/move_test_east_cell");

  return;
}
