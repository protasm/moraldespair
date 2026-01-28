inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Slick Narrow Way";
  long_desc = "The surface dips and rises where blocks have settled, leaving sharp lips and hollows. Blackened streaks and gouges run along the masonry, breaking any clean line. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1425",
    "south" : "/chapter/prologue/area/dead/room1427",
  ]);

  set_light(1);
}
