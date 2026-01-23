inherit "room/room";

void create() {
  ::create();

  short_desc = "Faded Split Way";
  long_desc = "Split slabs tilt against each other, their edges worn to chalk. The remains of pillars stand jagged, split and fused by old force. The path splits around a heap of fallen blocks, offering lines gone to ruin. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/indel/room1621",
    "east" : "/chapter/prologue/area/indel/room1515",
    "west" : "/chapter/prologue/area/indel/room1513",
  ]);

  set_light(1);
}
