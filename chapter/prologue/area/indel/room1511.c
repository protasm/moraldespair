inherit "room/room";

void create() {
  ::create();

  short_desc = "Faded Split Way";
  long_desc = "Rubble and crushed mortar blanket the surface, slick in places with old damp. The remains of pillars stand jagged, split and fused by old force. The path splits around a heap of fallen blocks, offering lines gone to ruin. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ({
    "chapter/prologue/area/indel/room1622", "north",
    "chapter/prologue/area/indel/room1512", "east",
    "chapter/prologue/area/indel/room1510", "west",
  });

  set_light(1);
}
