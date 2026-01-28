inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Temple Ruin";
  long_desc = "Broken columns and a fallen altar mark the remains of a temple. Vines trail\nthrough the shattered roofline.\n";
  dest_dir = ([
    "east":"/chapter/prologue/area/silent/room377",
    "west":"/chapter/prologue/area/silent/room375",
  ]);

  set_light(1);
}
