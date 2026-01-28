inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Cinder Walk";
  long_desc = "Cinder and gravel crunch over warped flagstones, the walk silent and weathered. Rusting hinges and charred lintels sag in rot and mildew, a dusty hint of shop doors left to decay.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room/room842",
    "east":"/chapter/prologue/area/ruined/room/room843",
    "north":"/chapter/prologue/area/ruined/room/room202",
  ]);

}
