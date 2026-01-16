inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Barrack Road";
  long_desc =
    "Long stone halls march along the street, their roofs partly fallen. Rusted\n"
    "nails and timbers lie in heaps.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room267", "east",
    "domain/original/area/anshelm/room269", "west",
  });
}
