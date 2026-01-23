inherit "room/room";

void create() {
  ::create();

  short_desc = "Charred Bleached Narrow Way";
  long_desc = "Loose stones shift underfoot, buried in silt and powdered mortar. Walls to either side are chewed by blasts and blade scars, their faces peeled away. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "east" : "/chapter/prologue/area/dead/room1406",
    "west" : "/chapter/prologue/area/dead/room1408",
  ]);

  set_light(1);
}
