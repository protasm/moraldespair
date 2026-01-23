inherit "room/room";

void create() {
  ::create();

  short_desc = "Rubble Split Way";
  long_desc = "Split slabs tilt against each other, their edges worn to chalk. Walls to either side are chewed by blasts and blade scars, their faces peeled away. The path splits around a heap of fallen blocks, offering lines gone to ruin. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "south" : "/chapter/prologue/area/dead/room1589",
    "east" : "/chapter/prologue/area/dead/room1407",
    "west" : "/chapter/prologue/area/dead/room1409",
  ]);

  set_light(1);
}
