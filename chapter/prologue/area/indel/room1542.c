inherit "room/room";

void create() {
  ::create();

  short_desc = "Scorched Sunk Split Way";
  long_desc = "The surface dips and rises where blocks have settled, leaving sharp lips and hollows. Chunks of wall have been scooped away, leaving raw ribs of stone. The path splits around a heap of fallen blocks, offering lines gone to ruin. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/indel/room1534",
    "east" : "/chapter/prologue/area/indel/room1591",
    "west" : "/chapter/prologue/area/indel/room1541",
  ]);

  set_light(1);
}
