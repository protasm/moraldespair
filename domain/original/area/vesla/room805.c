inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Sour Shed";
  long_desc = "The shed reeks of damp earth and rot, with sacks\n"
              + "collapsed into dark pulp. A battered scoop and\n"
              + "stained planks hint at soil and dung once bartered\n"
              + "here.\n";
  dest_dir = ({
    "domain/original/area/vesla/room802", "north",
  });
}
