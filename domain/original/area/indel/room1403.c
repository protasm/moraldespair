inherit "room/room";

void create() {
  ::create();

  short_desc = "Bleached Crossing";
  long_desc = "Broken paving lies in uneven ridges, with fine dust caked between. Walls to either side are chewed by blasts and blade scars, their faces peeled away. The way opens into a broad break where several ruined lines meet in silence. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ({
    "domain/original/area/indel/room1402", "north",
    "domain/original/area/indel/room1404", "south",
    "domain/original/area/indel/room1630", "east",
    "domain/original/area/indel/room1628", "west",
  });

  set_light(1);
}
