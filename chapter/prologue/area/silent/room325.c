inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Alley Bend";
  long_desc = "The alley turns around a sagging corner where bricks have slipped. Loose\nstones and soot gather along the base.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room326", "west",
    "chapter/prologue/area/silent/room324", "south",
  });
}
