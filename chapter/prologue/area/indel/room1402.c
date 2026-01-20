inherit "room/room";

void create() {
  ::create();

  short_desc = "Cracked Crossing";
  long_desc = "The ground is a mosaic of cracked slabs and loose grit, dulled by age. Walls to either side are chewed by blasts and blade scars, their faces peeled away. The way opens into a broad break where several ruined lines meet in silence. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ({
    "chapter/prologue/area/indel/room1401", "north",
    "chapter/prologue/area/indel/room1403", "south",
    "chapter/prologue/area/indel/room1633", "east",
    "chapter/prologue/area/indel/room1631", "west",
  });

  set_light(1);
}
