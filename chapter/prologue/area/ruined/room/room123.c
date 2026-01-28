inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Silent Walk";
  long_desc = "A quiet stretch of stone runs west, its seams filled with grit and grass. The remnants of a low railing sag along the edge, half buried in dust.";
  dest_dir = ([
    "west":"/chapter/prologue/area/ruined/room/room124",
    "east":"/chapter/prologue/area/ruined/room/room122",
    "north":"/chapter/prologue/area/ruined/room/room411",
  ]);

}
