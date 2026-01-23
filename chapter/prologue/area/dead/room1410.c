inherit "room/room";

void create() {
  ::create();

  short_desc = "Jagged Bleached Narrow Way";
  long_desc = "Grit and broken tiles lie in drifts, the ground uneven and tired. Walls to either side are chewed by blasts and blade scars, their faces peeled away. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "east" : "/chapter/prologue/area/dead/room1409",
    "west" : "/chapter/prologue/area/dead/room1411",
  ]);

  set_light(1);
}
