inherit "room/room";

void create() {
  ::create();

  short_desc = "Silent Walk";
  long_desc = "A quiet stretch of stone runs west, its seams filled with grit and grass. The remnants of a low railing sag along the edge, half buried in dust.";
  dest_dir = ([
    "west":"/chapter/prologue/area/ruined/room124",
    "east":"/chapter/prologue/area/ruined/room122",
    "north":"/chapter/prologue/area/ruined/room411",
  ]);

  set_light(1);
}
