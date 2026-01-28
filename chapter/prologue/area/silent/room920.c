inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Stone Foyer";
  long_desc = "Thick stone columns flank the entry to a broad hall. Their carvings are worn\nsmooth.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/silent/room923",
    "up":"/chapter/prologue/area/silent/room921",
    "south":"/chapter/prologue/area/silent/room333",
    "east":"/chapter/prologue/area/silent/room925",
    "north":"/chapter/prologue/area/silent/room924",
  ]);

  set_light(1);
}
