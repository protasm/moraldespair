inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Alley Bend";
  long_desc = "The alley turns around a sagging corner where bricks have slipped. Loose\nstones and soot gather along the base.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/silent/room326",
    "south":"/chapter/prologue/area/silent/room324",
  ]);

  set_light(1);
}
