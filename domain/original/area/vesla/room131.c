inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Westroad Drift";
  long_desc = "Windblown grit has gathered in thin drifts along the road. The stonework is\n"
              + "stained and pitted, and a few twisted iron bands cling to the wall.\n";
  dest_dir = ({
    "domain/original/area/vesla/room132", "west",
    "domain/original/area/vesla/room130", "east",
  });
}
