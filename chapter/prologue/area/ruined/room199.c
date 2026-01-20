inherit "room/room";

void create() {
  ::create();

  short_desc = "Mossed Way";
  long_desc = "Broken curbstones edge a long, silent way, their faces dark with mildew and rain stain. A scatter of toppled posts and empty brackets hints at old markers now swallowed by grit.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room200",
    "east":"/chapter/prologue/area/ruined/room962",
    "north":"/chapter/prologue/area/ruined/room198",
  ]);

  set_light(1);
}
