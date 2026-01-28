inherit "/room/room";

void create() {
  ::create();

  short_desc = "Bleached Narrow Way";
  long_desc = "Stone underfoot is split into plates, with grit and ash packed into the seams. Blackened streaks and gouges run along the masonry, breaking any clean line. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1420",
    "south" : "/chapter/prologue/area/dead/room1422",
  ]);

  set_light(1);
}
