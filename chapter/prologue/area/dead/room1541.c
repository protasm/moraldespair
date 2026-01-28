inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Sunk Narrow Way";
  long_desc = "Rubble and crushed mortar blanket the surface, slick in places with old damp. Chunks of wall have been scooped away, leaving raw ribs of stone. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "east" : "/chapter/prologue/area/dead/room1542",
    "west" : "/chapter/prologue/area/dead/room1540",
  ]);

  set_light(1);
}
