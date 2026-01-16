inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "West Barracks";
  long_desc =
    "The row of barracks breaks down into broken foundations. A sagging gate frame\n"
    "stands without doors.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room270", "east",
    "domain/original/area/anshelm/room272", "north",
  });
}
