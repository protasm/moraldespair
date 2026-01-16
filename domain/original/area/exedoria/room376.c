inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Temple Ruin";
  long_desc = "Broken columns and a fallen altar mark the remains of a temple. Vines trail\nthrough the shattered roofline.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room377", "east",
    "domain/original/area/exedoria/room375", "west",
  });
}
