inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Shattered Walk";
  long_desc = "The covered path is broken here, its ribs split and scattered across the paving. Wind drifts through the gaps, stirring leaves that have gathered in the hollows.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room/room222",
    "west":"/chapter/prologue/area/ruined/room/room120",
    "east":"/chapter/prologue/area/ruined/room/room118",
    "north":"/chapter/prologue/area/ruined/room/room230",
  ]);

}
