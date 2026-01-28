inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Basalt Corner";
  long_desc = "The road turns beside a wall of dark basalt blocks, their faces chipped and rough. A scatter of broken stone marks where another street has slumped away.";
  dest_dir = ([
    "west":"/chapter/prologue/area/ruined/room/room134",
    "east":"/chapter/prologue/area/ruined/room/room132",
    "south":"/chapter/prologue/area/ruined/room/room135",
  ]);

}
