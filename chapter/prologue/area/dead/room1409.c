inherit "/room/room";

void create() {
  ::create();

  short_desc = "Bleached Split Way";
  long_desc = "Pitted stone stretches ahead, littered with chips and fragments. Walls to either side are chewed by blasts and blade scars, their faces peeled away. The path splits around a heap of fallen blocks, offering lines gone to ruin. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "south" : "/chapter/prologue/area/dead/room1590",
    "east" : "/chapter/prologue/area/dead/room1408",
    "west" : "/chapter/prologue/area/dead/room1410",
  ]);

  set_light(1);
}
