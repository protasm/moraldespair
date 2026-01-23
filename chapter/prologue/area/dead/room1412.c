inherit "room/room";

void create() {
  ::create();

  short_desc = "Bleached Narrow Way";
  long_desc = "The ground is a mosaic of cracked slabs and loose grit, dulled by age. Leaning walls show long cuts and scorch trails, as if steel and heat worried them for hours. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "east" : "/chapter/prologue/area/dead/room1411",
    "west" : "/chapter/prologue/area/dead/room1413",
  ]);

  set_light(1);
}
