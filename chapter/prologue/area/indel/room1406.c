inherit "room/room";

void create() {
  ::create();

  short_desc = "Bleached Crossing";
  long_desc = "The surface dips and rises where blocks have settled, leaving sharp lips and hollows. Walls to either side are chewed by blasts and blade scars, their faces peeled away. The way opens into a broad break where several ruined lines meet in silence. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ({
    "chapter/prologue/area/indel/room1405", "north",
    "chapter/prologue/area/indel/room1584", "south",
    "chapter/prologue/area/indel/room1508", "east",
    "chapter/prologue/area/indel/room1407", "west",
  });

  set_light(1);
}
