inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "West Roof";
  long_desc =
    "The roof is bare to the sky, ringed by a broken parapet. Pooled rainwater\n"
    "glints in shallow basins.\n";
  dest_dir = ([
    "down" : "/chapter/prologue/area/refuge/room1139",
  ]);

  set_light(1);
}
