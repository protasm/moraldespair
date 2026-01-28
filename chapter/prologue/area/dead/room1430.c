inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Bleached Narrow Way";
  long_desc = "Grit and broken tiles lie in drifts, the ground uneven and tired. Blackened streaks and gouges run along the masonry, breaking any clean line. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1429",
    "south" : "/chapter/prologue/area/dead/room1431",
  ]);

  set_light(1);
}
