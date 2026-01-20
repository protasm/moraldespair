inherit "room/room";

void create() {
  ::create();

  short_desc = "Overgrown Park";
  long_desc = "Thick grass swallows old benches, leaving warped planks and rusted bolts. A sagging iron fence lists inward, half-buried in leaf mold.";
  dest_dir = ([
    "north":"/chapter/prologue/area/ruined/room228",
    "south":"/chapter/prologue/area/ruined/room118",
    "east":"/chapter/prologue/area/ruined/room226",
    "west":"/chapter/prologue/area/ruined/room230",
  ]);

  set_light(1);
}


