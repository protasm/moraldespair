inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Alley End";
  long_desc = "The alley narrows to a dead end cluttered with collapsed beams. Damp stains\nrun down the brick where rooflines failed.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room323", "south",
    "chapter/prologue/area/silent/room325", "north",
  });
}
