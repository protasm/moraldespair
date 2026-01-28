inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Stone Cell";
  long_desc = "The cell is spare and silent, its floor worn smooth. Moisture beads on the\ncorners.\n";
  dest_dir = ([
    "east":"/chapter/prologue/area/silent/room364",
  ]);

  set_light(1);
}
