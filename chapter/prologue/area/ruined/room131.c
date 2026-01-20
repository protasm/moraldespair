inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Westroad Drift";
  long_desc = "Windblown grit has gathered in thin drifts along the road. The stonework is stained and pitted, and a few twisted iron bands cling to the wall.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room132", "west",
    "chapter/prologue/area/ruined/room130", "east",
  });
}
