inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Park Cross";
  long_desc = "Two narrow paths cross under a thinning canopy. Fallen limbs lie where the\nwalkways once met cleanly.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room370",
    "west":"/chapter/prologue/area/silent/room372",
    "east":"/chapter/prologue/area/silent/room378",
    "north":"/chapter/prologue/area/silent/room373",
  ]);

  set_light(1);
}
