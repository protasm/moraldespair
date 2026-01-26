inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Grit-Streaked Crossing";
  long_desc = "Weathered stones mark the meeting of two old streets, their lines softened by drifted grit. A broken post leans over the junction, and no track has passed in generations.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room/room220",
    "west":"/chapter/prologue/area/ruined/room/room118",
    "east":"/chapter/prologue/area/ruined/room/room116",
    "north":"/chapter/prologue/area/ruined/room/room226",
  ]);

}
