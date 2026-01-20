inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Small Den";
  long_desc = "A low room sits tucked under a stair, its walls scratched and scuffed. A toy\nchest lies smashed in a corner.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room909", "east",
  });
}
