inherit "room/room";

void create() {
  ::create();

  short_desc = "Sunk Narrow Way";
  long_desc = "The surface dips and rises where blocks have settled, leaving sharp lips and hollows. Jagged ribs of stone show cuts and pitting, some edges glassed by heat. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/indel/room1563",
    "south" : "/chapter/prologue/area/indel/room1561",
  ]);

  set_light(1);
}
