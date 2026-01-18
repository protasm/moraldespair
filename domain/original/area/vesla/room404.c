inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Dusty Nave";
  long_desc = "Tall columns loom over a nave littered with fallen tiles and windblown dust. A cracked altar slab sits beneath a roof opened to rain, and the air carries mildew from sodden tapestries curled against the walls.";
  dest_dir = ({
    "domain/original/area/vesla/room405", "east",
    "domain/original/area/vesla/room403", "west",
  });
}
