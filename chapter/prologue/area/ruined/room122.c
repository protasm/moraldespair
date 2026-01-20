inherit "room/room";

void create() {
  ::create();

  short_desc = "Withered Walk";
  long_desc = "The path narrows beneath the remains of a withered canopy. Splintered slats litter the ground, and the walls are dark with rain stains and age.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room225",
    "west":"/chapter/prologue/area/ruined/room123",
    "east":"/chapter/prologue/area/ruined/room121",
    "north":"/chapter/prologue/area/ruined/room410",
  ]);

  set_light(1);
}
