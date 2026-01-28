inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "West Barracks";
  long_desc =
    "The row of barracks breaks down into broken foundations. A sagging gate frame\n"
    "stands without doors.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/refuge/room270",
    "north" : "/chapter/prologue/area/refuge/room272",
  ]);

  set_light(1);
}
