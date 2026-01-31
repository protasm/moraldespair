inherit "/chapter/prologue/std/room";

int leg_shackled;
object east_exit;

void create() {
  ::create();

  short_desc = "Players' Lounge";
  long_desc = "You stand in the hollowed remains of the lounge, a room that once buzzed with the gossip and fevered arguments of long-dead legends. Now, the only sound is the whistling of wind through the cracked, soot-stained windows that line the walls. A shimmering blue portal still flickers weakly in the center, its light pulsing like a dying heart as it leads upward.\n\nSomebody has temporarily added a few movement-testing exits in the cardinal directions.";

  leg_shackled = 0;
  add_exit("down", "sanctuary");
  add_exit("north", "move_test_north");
  add_exit("south", "move_test_south");
  east_exit = add_exit_object(
    new("/chapter/prologue/area/ruined/room/lounge_east_exit"),
    "east",
    "move_test_east"
  );
  add_exit("west", "move_test_west");

}

int pre_leave(object exit) {
  if (objectp(exit) && exit->use_word() == "east") {
    if (leg_shackled) {
      write("The shackles keep you from heading east.\n");

      return 0;
    }
  }

  return 1;
}
