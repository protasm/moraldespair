inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Lane Start";
  long_desc = "A narrow lane begins between sagging houses. The stones are uneven and broken.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room309", "south",
    "domain/original/area/exedoria/room307", "north",
  });
}
