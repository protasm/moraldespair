inherit "room/room";

void create() {
  ::create();

  short_desc = "Jagged Split Way";
  long_desc = "Grit and broken tiles lie in drifts, the ground uneven and tired. Chunks of wall have been scooped away, leaving raw ribs of stone. The path splits around a heap of fallen blocks, offering lines gone to ruin. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1543",
    "east" : "/chapter/prologue/area/dead/room1547",
    "west" : "/chapter/prologue/area/dead/room1545",
  ]);

  set_light(1);
}
