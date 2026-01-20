inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Silent Row";
  long_desc = "The street feels ceremonial, though no one walks it now. Even the paving here\nis fractured and dull.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room316", "west",
    "chapter/prologue/area/silent/room323", "east",
    "chapter/prologue/area/silent/room333", "north",
  });
}
