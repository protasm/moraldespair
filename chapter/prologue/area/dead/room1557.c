inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Fractured Sunk Narrow Way";
  long_desc = "Stone underfoot is split into plates, with grit and ash packed into the seams. Jagged ribs of stone show cuts and pitting, some edges glassed by heat. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "east" : "/chapter/prologue/area/dead/room1535",
    "west" : "/chapter/prologue/area/dead/room1556",
  ]);

  set_light(1);
}
