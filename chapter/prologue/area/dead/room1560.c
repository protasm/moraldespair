inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Hollow Sunk Narrow Way";
  long_desc = "The floor is a churn of fractured stone and rubble, pressed flat by time. Jagged ribs of stone show cuts and pitting, some edges glassed by heat. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1561",
    "south" : "/chapter/prologue/area/dead/room1559",
  ]);

  set_light(1);
}
