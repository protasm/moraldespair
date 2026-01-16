inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Rutted Street";
  long_desc = "Thin grass grows in the grooves left by carts. Loose brick and fallen beams\ndot the edges of the street.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room296", "east",
    "domain/original/area/exedoria/room294", "west",
  });
}
