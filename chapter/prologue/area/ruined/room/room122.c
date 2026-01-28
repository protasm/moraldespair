inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Withered Walk";
  long_desc = "The path narrows beneath the remains of a withered canopy. Splintered slats litter the ground, and the walls are dark with rain stains and age.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room/room225",
    "west":"/chapter/prologue/area/ruined/room/room123",
    "east":"/chapter/prologue/area/ruined/room/room121",
    "north":"/chapter/prologue/area/ruined/room/room410",
  ]);

}
