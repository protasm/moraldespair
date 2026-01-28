inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Empty Junction";
  long_desc = "A wide junction opens where several streets once met. The stones are worn smooth, and scattered rubble marks where structures have slumped into the road.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room/room159",
    "west":"/chapter/prologue/area/ruined/room/room126",
    "east":"/chapter/prologue/area/ruined/room/room124",
    "north":"/chapter/prologue/area/ruined/room/room160",
  ]);

}
