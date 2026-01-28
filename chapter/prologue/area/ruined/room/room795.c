inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Narrow Cut";
  long_desc = "The alley narrows between damp walls, with soot and slime streaking the stone. Old drainage grooves and a collapsed plank hint at service traffic that no longer comes.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room/room813",
    "west":"/chapter/prologue/area/ruined/room/room792",
    "east":"/chapter/prologue/area/ruined/room/room796",
    "north":"/chapter/prologue/area/ruined/room/room797",
  ]);

}
