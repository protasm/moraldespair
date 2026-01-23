inherit "room/room";

void create() {
  ::create();

  short_desc = "Cracked Faded Narrow Way";
  long_desc = "Loose stones shift underfoot, buried in silt and powdered mortar. Fragments of arches and lintels hang at odd angles, cut and burned through. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1436",
    "south" : "/chapter/prologue/area/dead/room1438",
  ]);

  set_light(1);
}
