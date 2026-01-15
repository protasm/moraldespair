inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Faded Curios";
  long_desc = "Narrow shelves sag under warped boxes and tarnished curios, all buried in\n"
              + "dust. The air is sweet with mildew, and the floorboards have bowed around a\n"
              + "collapsed display case. A cracked mirror leans in back, its gilt peeling away.\n";
  dest_dir = ({
    "domain/original/area/vesla/room208", "south",
  });
}
