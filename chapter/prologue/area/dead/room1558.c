inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Seamed Narrow Way";
  long_desc = "The ground is a mosaic of cracked slabs and loose grit, dulled by age. Jagged ribs of stone show cuts and pitting, some edges glassed by heat. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1559",
    "south" : "/chapter/prologue/area/dead/room1544",
  ]);

  set_light(1);
}
