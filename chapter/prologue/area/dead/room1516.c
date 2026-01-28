inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Splintered Split Way";
  long_desc = "Grit and broken tiles lie in drifts, the ground uneven and tired. The remains of pillars stand jagged, split and fused by old force. The path splits around a heap of fallen blocks, offering lines gone to ruin. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "south" : "/chapter/prologue/area/dead/room1520",
    "east" : "/chapter/prologue/area/dead/room1517",
    "west" : "/chapter/prologue/area/dead/room1515",
  ]);

  set_light(1);
}
