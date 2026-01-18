inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Withered Walk";
  long_desc = "The path narrows beneath the remains of a withered canopy. Splintered slats litter the ground, and the walls are dark with rain stains and age.";
  dest_dir = ({
    "domain/original/area/vesla/room225", "south",
    "domain/original/area/vesla/room123", "west",
    "domain/original/area/vesla/room121", "east",
    "domain/original/area/vesla/room410", "north",
  });
}
