inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Players' Lounge";
  long_desc =
    "This lounge is a staging area for link demos, and the text is\n"
    "deliberately out of character so the commands are clear. North leads\n"
    "to a foyer with two hatches that share a name, so use 'open east hatch'\n"
    "or 'open west hatch' there. East shows a one-sided latch with 'lock\n"
    "latch demo' and 'unlock latch demo', while south leads to two doors\n"
    "around rubble that respond to 'open door 1' and 'open door 2'.";

  /*Obsolete Code = ignore, do not emulate
  add_exit("down", "sanctuary");
  add_exit("north", "move_test_north");
  add_exit("south", "move_test_south");
  east_exit = add_exit_object(
    new("/chapter/prologue/area/ruined/room/lounge_east_exit"),
    "east",
    "move_test_east"
  );
  add_exit("west", "move_test_west");
  */
}
