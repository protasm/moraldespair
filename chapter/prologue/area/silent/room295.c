inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Rutted Street";
  long_desc = "Thin grass grows in the grooves left by carts. Loose brick and fallen beams\ndot the edges of the street.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room296", "east",
    "chapter/prologue/area/silent/room294", "west",
  });
}
