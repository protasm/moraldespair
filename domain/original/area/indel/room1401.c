inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Broken Bleached Crossing";
  long_desc =
    "Stone underfoot is split into plates, with grit and ash packed into the seams.\n"
    "Walls to either side are chewed by blasts and blade scars, their faces peeled\n"
    "away.\n"
    "\n"
    "The way opens into a broad break where several ruined lines meet in silence.\n"
    "Moss and pale mold cling to the damp pockets, and nothing moves except drifting\n"
    "grit.\n";
  dest_dir = ({
    "domain/original/area/indel/room1402", "south",
    "domain/original/area/indel/room1636", "east",
    "domain/original/area/indel/room1635", "west",
    "domain/original/area/indel/entrance", "exit",
  });

  add_exit_alias("x", "exit");
}
