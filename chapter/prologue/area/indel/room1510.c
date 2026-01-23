inherit "room/room";

void create() {
  ::create();

  short_desc = "Collapsed Split Way";
  long_desc = "The floor is a churn of fractured stone and rubble, pressed flat by time. The remains of pillars stand jagged, split and fused by old force. The path splits around a heap of fallen blocks, offering lines gone to ruin. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/indel/room1623",
    "east" : "/chapter/prologue/area/indel/room1511",
    "west" : "/chapter/prologue/area/indel/room1509",
  ]);

  set_light(1);
}
