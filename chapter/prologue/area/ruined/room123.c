inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Silent Walk";
  long_desc = "A quiet stretch of stone runs west, its seams filled with grit and grass. The remnants of a low railing sag along the edge, half buried in dust.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room124", "west",
    "chapter/prologue/area/ruined/room122", "east",
    "chapter/prologue/area/ruined/room411", "north",
  });
}
