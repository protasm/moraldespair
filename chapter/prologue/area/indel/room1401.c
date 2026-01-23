inherit "room/room";

void create() {
  ::create();

  short_desc = "Broken Bleached Crossing";
  long_desc = "Stone underfoot is split into plates, with grit and ash packed into the seams. Walls to either side are chewed by blasts and blade scars, their faces peeled away. The way opens into a broad break where several ruined lines meet in silence. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "south" : "/chapter/prologue/area/indel/room1402",
    "east" : "/chapter/prologue/area/indel/room1636",
    "west" : "/chapter/prologue/area/indel/room1635",
    "exit" : "/chapter/prologue/area/indel/entrance",
  ]);

  add_exit_alias("x", "exit");

  set_light(1);
}
