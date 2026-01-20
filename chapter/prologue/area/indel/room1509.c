inherit "room/room";

void create() {
  ::create();

  short_desc = "Rubble Faded Split Way";
  long_desc = "Broken paving lies in uneven ridges, with fine dust caked between. The remains of pillars stand jagged, split and fused by old force. The path splits around a heap of fallen blocks, offering lines gone to ruin. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ({
    "chapter/prologue/area/indel/room1624", "north",
    "chapter/prologue/area/indel/room1510", "east",
    "chapter/prologue/area/indel/room1508", "west",
  });

  set_light(1);
}
