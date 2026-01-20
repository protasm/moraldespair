inherit "room/room";

void create() {
  ::create();

  short_desc = "West Roof";
  long_desc =
    "The roof is bare to the sky, ringed by a broken parapet. Pooled rainwater\n"
    "glints in shallow basins.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1139", "down",
  });

  set_light(1);
}
