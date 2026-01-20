inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Temple Ruin";
  long_desc = "Broken columns and a fallen altar mark the remains of a temple. Vines trail\nthrough the shattered roofline.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room377", "east",
    "chapter/prologue/area/silent/room375", "west",
  });
}
