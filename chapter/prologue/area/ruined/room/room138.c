inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Basalt Avenue";
  long_desc = "Basalt blocks crowd the street, their faces chipped and dark with thick soot. Doorways gape into shadow, and the avenue is filmed with fine dust and leaf rot.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room/room139",
    "west":"/chapter/prologue/area/ruined/room/room856",
    "east":"/chapter/prologue/area/ruined/room/room855",
    "north":"/chapter/prologue/area/ruined/room/room137",
  ]);

}
