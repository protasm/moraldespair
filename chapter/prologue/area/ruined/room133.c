inherit "room/room";

void create() {
  ::create();

  short_desc = "Basalt Corner";
  long_desc = "The road turns beside a wall of dark basalt blocks, their faces chipped and rough. A scatter of broken stone marks where another street has slumped away.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room134", "west",
    "chapter/prologue/area/ruined/room132", "east",
    "chapter/prologue/area/ruined/room135", "south",
  });

  set_light(1);
}
