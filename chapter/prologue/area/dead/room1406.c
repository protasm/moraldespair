inherit "/room/room";

void create() {
  ::create();

  short_desc = "Bleached Crossing";
  long_desc = "The surface dips and rises where blocks have settled, leaving sharp lips and hollows. Walls to either side are chewed by blasts and blade scars, their faces peeled away. The way opens into a broad break where several ruined lines meet in silence. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1405",
    "south" : "/chapter/prologue/area/dead/room1584",
    "east" : "/chapter/prologue/area/dead/room1508",
    "west" : "/chapter/prologue/area/dead/room1407",
  ]);

  set_light(1);
}
