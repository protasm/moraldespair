inherit "room/room";

void create() {
  ::create();

  short_desc = "Bleached Narrow Way";
  long_desc = "The ground is a mosaic of cracked slabs and loose grit, dulled by age. Fragments of arches and lintels hang at odd angles, cut and burned through. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1431",
    "south" : "/chapter/prologue/area/dead/room1433",
  ]);

  set_light(1);
}
