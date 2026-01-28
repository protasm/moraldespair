inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Silent Hearth";
  long_desc = "A wide, cold hearth sits beneath a soot-dark mantle, the room silent and ruined. Rotted tables lean in dust and mildew, and the common space is left to sag.";
  dest_dir = ([
    "west":"/chapter/prologue/area/ruined/room/room142",
    "east":"/chapter/prologue/area/ruined/room/room852",
    "north":"/chapter/prologue/area/ruined/room/room851",
  ]);

}
