inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Ruined Narrow Way";
  long_desc = "Split slabs tilt against each other, their edges worn to chalk. Jagged ribs of stone show cuts and pitting, some edges glassed by heat. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1565",
    "south" : "/chapter/prologue/area/dead/room1563",
  ]);

  set_light(1);
}
