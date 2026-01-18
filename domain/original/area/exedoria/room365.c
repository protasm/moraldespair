inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Stone Cell";
  long_desc = "The cell is spare and silent, its floor worn smooth. Moisture beads on the\ncorners.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room364", "east",
  });
}
