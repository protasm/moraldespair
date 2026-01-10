inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Westroad Drift";
  long_desc = "Windblown grit has gathered in thin drifts along the road.\n"
              + "The stonework is stained and pitted, and a few twisted iron\n"
              + "bands cling to the wall.\n";
  dest_dir = ({
    "domain/original/area/vesla/room132", "west",
    "domain/original/area/vesla/room130", "east",
    "domain/original/area/vesla/room858", "north",
  });
}
