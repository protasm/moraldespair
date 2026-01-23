inherit "room/room";

void create() {
  ::create();

  short_desc = "Bleached Faded Split Way";
  long_desc = "Loose stones shift underfoot, buried in silt and powdered mortar. The stonework is torn open, exposing fill and roots, with scorch marks in the cracks. The path splits around a heap of fallen blocks, offering lines gone to ruin. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1532",
    "south" : "/chapter/prologue/area/dead/room1534",
    "east" : "/chapter/prologue/area/dead/room1597",
  ]);

  set_light(1);
}
