inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Dusty Nave";
  long_desc = "Tall columns loom over a nave littered with fallen tiles and windblown dust. A cracked altar slab sits beneath a roof opened to rain, and the air carries mildew from sodden tapestries curled against the walls.";
  dest_dir = ([
    "east":"/chapter/prologue/area/ruined/room/room405",
    "west":"/chapter/prologue/area/ruined/room/room403",
  ]);

}
