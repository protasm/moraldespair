inherit "room/room";

void create() {
  ::create();

  short_desc = "Rutted Street";
  long_desc = "Thin grass grows in the grooves left by carts. Loose brick and fallen beams\ndot the edges of the street.\n";
  dest_dir = ([
    "east":"/chapter/prologue/area/silent/room296",
    "west":"/chapter/prologue/area/silent/room294",
  ]);

  set_light(1);
}
