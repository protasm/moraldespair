inherit "room/room";

void create() {
  ::create();

  short_desc = "Bleached Split Way";
  long_desc = "Split slabs tilt against each other, their edges worn to chalk. Leaning walls show long cuts and scorch trails, as if steel and heat worried them for hours. The path splits around a heap of fallen blocks, offering lines gone to ruin. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1448",
    "south" : "/chapter/prologue/area/dead/room1419",
    "east" : "/chapter/prologue/area/dead/room1417",
  ]);

  set_light(1);
}
