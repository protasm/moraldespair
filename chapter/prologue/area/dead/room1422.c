inherit "room/room";

void create() {
  ::create();

  short_desc = "Seamed Bleached Narrow Way";
  long_desc = "The ground is a mosaic of cracked slabs and loose grit, dulled by age. Blackened streaks and gouges run along the masonry, breaking any clean line. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1421",
    "south" : "/chapter/prologue/area/dead/room1423",
  ]);

  set_light(1);
}
