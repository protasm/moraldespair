inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Westroad Silence";
  long_desc = "The road narrows into a quiet channel of stone and dust. A collapsed lintel lies across one wall, and the space beyond it is dark and empty.";
  dest_dir = ([
    "west":"/chapter/prologue/area/ruined/room/room131",
    "east":"/chapter/prologue/area/ruined/room/room129",
    "south":"/chapter/prologue/area/ruined/room/room420",
  ]);

}
