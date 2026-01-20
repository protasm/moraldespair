inherit "room/room";

void create() {
  ::create();

  short_desc = "Park Cross";
  long_desc = "Two narrow paths cross under a thinning canopy. Fallen limbs lie where the\nwalkways once met cleanly.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room370", "south",
    "chapter/prologue/area/silent/room372", "west",
    "chapter/prologue/area/silent/room378", "east",
    "chapter/prologue/area/silent/room373", "north",
  });

  set_light(1);
}
