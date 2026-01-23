inherit "room/room";

void create() {
  ::create();

  short_desc = "Blasted Narrow Way";
  long_desc = "Loose stones shift underfoot, buried in silt and powdered mortar. The remains of pillars stand jagged, split and fused by old force. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "east" : "/chapter/prologue/area/dead/room1514",
    "west" : "/chapter/prologue/area/dead/room1512",
  ]);

  set_light(1);
}
