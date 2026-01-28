inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Leaning Narrow Way";
  long_desc = "Broken paving lies in uneven ridges, with fine dust caked between. Blackened streaks and gouges run along the masonry, breaking any clean line. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1422",
    "south" : "/chapter/prologue/area/dead/room1424",
  ]);

  set_light(1);
}
