inherit "room/room";

void create() {
  ::create();

  short_desc = "Dusty Nave";
  long_desc = "Tall columns loom over a nave littered with fallen tiles and windblown dust. A cracked altar slab sits beneath a roof opened to rain, and the air carries mildew from sodden tapestries curled against the walls.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room405", "east",
    "chapter/prologue/area/ruined/room403", "west",
  });

  set_light(1);
}
