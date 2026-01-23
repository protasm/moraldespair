inherit "room/room";

void create() {
  ::create();

  short_desc = "Sundered Sunk Narrow Way";
  long_desc = "Broken paving lies in uneven ridges, with fine dust caked between. Chunks of wall have been scooped away, leaving raw ribs of stone. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "east" : "/chapter/prologue/area/indel/room1540",
    "west" : "/chapter/prologue/area/indel/room1538",
  ]);

  set_light(1);
}
