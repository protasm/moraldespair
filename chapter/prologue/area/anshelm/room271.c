inherit "room/room";

void create() {
  ::create();

  short_desc = "West Barracks";
  long_desc =
    "The row of barracks breaks down into broken foundations. A sagging gate frame\n"
    "stands without doors.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room270", "east",
    "chapter/prologue/area/anshelm/room272", "north",
  });

  set_light(1);
}
