inherit "room/room";

void create() {
  ::create();

  short_desc = "Stone Foyer";
  long_desc = "Thick stone columns flank the entry to a broad hall. Their carvings are worn\nsmooth.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room923", "west",
    "chapter/prologue/area/silent/room921", "up",
    "chapter/prologue/area/silent/room333", "south",
    "chapter/prologue/area/silent/room925", "east",
    "chapter/prologue/area/silent/room924", "north",
  });

  set_light(1);
}
