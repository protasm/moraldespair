inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Windmill Base";
  long_desc = "The base of a windmill stands open to the wind, its beams creaking. Grain dust\nhas long settled into the floor.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room929", "up",
    "domain/original/area/exedoria/room927", "west",
    "domain/original/area/exedoria/room928", "east",
    "domain/original/area/exedoria/room319", "south",
  });
}
