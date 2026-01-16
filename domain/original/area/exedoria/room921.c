inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Stone Watch";
  long_desc = "A squat tower rises above the wall, its stairs broken. The top is open to rain\nand birds.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room920", "down",
    "domain/original/area/exedoria/room922", "north",
  });
}
