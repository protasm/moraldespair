inherit "room/room";

void create() {
  ::create();

  short_desc = "Scorched Choked End";
  long_desc = "Stone underfoot is split into plates, with grit and ash packed into the seams. The remains of pillars stand jagged, split and fused by old force. A collapsed heap chokes the line, the passage left to cave in. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "south" : "/chapter/prologue/area/dead/room1448",
  ]);

  set_light(1);
}
