inherit "/room/room";

void create() {
  ::create();

  short_desc = "Rubble Faded Split Way";
  long_desc = "Broken paving lies in uneven ridges, with fine dust caked between. The remains of pillars stand jagged, split and fused by old force. The path splits around a heap of fallen blocks, offering lines gone to ruin. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1624",
    "east" : "/chapter/prologue/area/dead/room1510",
    "west" : "/chapter/prologue/area/dead/room1508",
  ]);

  set_light(1);
}
