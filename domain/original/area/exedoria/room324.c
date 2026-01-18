inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Alley End";
  long_desc = "The alley narrows to a dead end cluttered with collapsed beams. Damp stains\nrun down the brick where rooflines failed.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room323", "south",
    "domain/original/area/exedoria/room325", "north",
  });
}
