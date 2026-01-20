inherit "room/room";

void create() {
  ::create();

  short_desc = "Worn Crossing";
  long_desc = "Two worn streets cross on uneven basalt, their corners softened by age and grit. The stones are cracked and slumped, leaving shallow puddles and windblown grit.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room138", "south",
    "chapter/prologue/area/ruined/room193", "east",
    "chapter/prologue/area/ruined/room136", "north",
  });

  set_light(1);
}

