inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Park Cross";
  long_desc = "Two narrow paths cross under a thinning canopy. Fallen limbs lie where the\nwalkways once met cleanly.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room370", "south",
    "domain/original/area/exedoria/room372", "west",
    "domain/original/area/exedoria/room378", "east",
    "domain/original/area/exedoria/room373", "north",
  });
}
