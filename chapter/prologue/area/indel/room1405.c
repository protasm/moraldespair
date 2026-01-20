inherit "room/room";

void create() {
  ::create();

  short_desc = "Choked Split Way";
  long_desc = "Rubble and crushed mortar blanket the surface, slick in places with old damp. Walls to either side are chewed by blasts and blade scars, their faces peeled away. The path splits around a heap of fallen blocks, offering lines gone to ruin. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ({
    "chapter/prologue/area/indel/room1404", "north",
    "chapter/prologue/area/indel/room1406", "south",
    "chapter/prologue/area/indel/room1625", "west",
  });

  set_light(1);
}
