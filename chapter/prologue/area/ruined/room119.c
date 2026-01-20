inherit "room/room";

void create() {
  ::create();

  short_desc = "Shattered Walk";
  long_desc = "The covered path is broken here, its ribs split and scattered across the paving. Wind drifts through the gaps, stirring leaves that have gathered in the hollows.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room222",
    "west":"/chapter/prologue/area/ruined/room120",
    "east":"/chapter/prologue/area/ruined/room118",
    "north":"/chapter/prologue/area/ruined/room230",
  ]);

  set_light(1);
}
