inherit "room/room";

void create() {
  ::create();

  short_desc = "Sunk Narrow Way";
  long_desc = "Split slabs tilt against each other, their edges worn to chalk. Chunks of wall have been scooped away, leaving raw ribs of stone. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/indel/room1558",
    "south" : "/chapter/prologue/area/indel/room1543",
  ]);

  set_light(1);
}
