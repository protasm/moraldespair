inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Dust Court";
  long_desc = "Dust drifts along the open court, pooling against slumped walls and empty doorways. The stones are worn smooth in a broad path, the track of forgotten patrols.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room/room756",
    "northeast":"/chapter/prologue/area/ruined/room/room765",
    "east":"/chapter/prologue/area/ruined/room/room758",
    "north":"/chapter/prologue/area/ruined/room/room766",
  ]);

}
