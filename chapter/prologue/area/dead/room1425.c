inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Silted Bleached Narrow Way";
  long_desc = "Rubble and crushed mortar blanket the surface, slick in places with old damp. Blackened streaks and gouges run along the masonry, breaking any clean line. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1424",
    "south" : "/chapter/prologue/area/dead/room1426",
  ]);

  set_light(1);
}
