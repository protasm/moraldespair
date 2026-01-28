inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Worn Crossing";
  long_desc = "Two worn streets cross on uneven basalt, their corners softened by age and grit. The stones are cracked and slumped, leaving shallow puddles and windblown grit.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room/room138",
    "east":"/chapter/prologue/area/ruined/room/room193",
    "north":"/chapter/prologue/area/ruined/room/room136",
  ]);

}

