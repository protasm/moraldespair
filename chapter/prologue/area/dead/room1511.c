inherit "room/room";

void create() {
  ::create();

  short_desc = "Faded Split Way";
  long_desc = "Rubble and crushed mortar blanket the surface, slick in places with old damp. The remains of pillars stand jagged, split and fused by old force. The path splits around a heap of fallen blocks, offering lines gone to ruin. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1622",
    "east" : "/chapter/prologue/area/dead/room1512",
    "west" : "/chapter/prologue/area/dead/room1510",
  ]);

  set_light(1);
}
