inherit "room/room";

void create() {
  ::create();

  short_desc = "Broken Bleached Crossing";
  long_desc = "Stone underfoot is split into plates, with grit and ash packed into the seams. Walls to either side are chewed by blasts and blade scars, their faces peeled away. The way opens into a broad break where several ruined lines meet in silence. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ({
    "chapter/prologue/area/indel/room1402", "south",
    "chapter/prologue/area/indel/room1636", "east",
    "chapter/prologue/area/indel/room1635", "west",
    "chapter/prologue/area/indel/entrance", "exit",
  });

  add_exit_alias("x", "exit");

  set_light(1);
}
