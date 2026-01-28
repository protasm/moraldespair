inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Fallen Shrine";
  long_desc = "Stone benches sit in crooked rows, their edges rounded by damp and rot. A shallow brazier lies overturned near the front, its iron scaled with rust and its embers long gone.";
  dest_dir = ([
    "west":"/chapter/prologue/area/ruined/room/room404",
    "south":"/chapter/prologue/area/ruined/room/room407",
    "north":"/chapter/prologue/area/ruined/room/room406",
  ]);

}
