inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Bleached Narrow Way";
  long_desc = "Loose stones shift underfoot, buried in silt and powdered mortar. Blackened streaks and gouges run along the masonry, breaking any clean line. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1426",
    "south" : "/chapter/prologue/area/dead/room1428",
  ]);

  set_light(1);
}
