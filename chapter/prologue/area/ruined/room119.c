inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Shattered Walk";
  long_desc = "The covered path is broken here, its ribs split and scattered across the paving. Wind drifts through the gaps, stirring leaves that have gathered in the hollows.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room222", "south",
    "chapter/prologue/area/ruined/room120", "west",
    "chapter/prologue/area/ruined/room118", "east",
    "chapter/prologue/area/ruined/room230", "north",
  });
}
