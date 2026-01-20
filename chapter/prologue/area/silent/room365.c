inherit "room/room";

void create() {
  ::create();

  short_desc = "Stone Cell";
  long_desc = "The cell is spare and silent, its floor worn smooth. Moisture beads on the\ncorners.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room364", "east",
  });

  set_light(1);
}
