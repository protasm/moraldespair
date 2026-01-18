inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Stone Foyer";
  long_desc = "Thick stone columns flank the entry to a broad hall. Their carvings are worn\nsmooth.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room923", "west",
    "domain/original/area/exedoria/room921", "up",
    "domain/original/area/exedoria/room333", "south",
    "domain/original/area/exedoria/room925", "east",
    "domain/original/area/exedoria/room924", "north",
  });
}
