inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Silent Row";
  long_desc = "The street feels ceremonial, though no one walks it now. Even the paving here\nis fractured and dull.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room316", "west",
    "domain/original/area/exedoria/room323", "east",
    "domain/original/area/exedoria/room333", "north",
  });
}
