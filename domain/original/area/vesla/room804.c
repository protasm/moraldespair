inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Brine Stall";
  long_desc = "Brine has long dried into a crust, leaving the stall rank and silent.\n"
              + "Splintered tables and a rusted hook hint at trade in flesh that has since\n"
              + "rotted away.\n";
  dest_dir = ({
    "domain/original/area/vesla/room803", "north",
  });
}
