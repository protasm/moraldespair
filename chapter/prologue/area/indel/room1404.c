inherit "room/room";

void create() {
  ::create();

  short_desc = "Mossy Bleached Crossing";
  long_desc = "The floor is a churn of fractured stone and rubble, pressed flat by time. Walls to either side are chewed by blasts and blade scars, their faces peeled away. The way opens into a broad break where several ruined lines meet in silence. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/indel/room1403",
    "south" : "/chapter/prologue/area/indel/room1405",
    "east" : "/chapter/prologue/area/indel/room1627",
    "west" : "/chapter/prologue/area/indel/room1626",
  ]);

  set_light(1);
}
