inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "West Roof";
  long_desc =
    "The roof is bare to the sky, ringed by a broken parapet. Pooled rainwater\n"
    "glints in shallow basins.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1139", "down",
  });
}
