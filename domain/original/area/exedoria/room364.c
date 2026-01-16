inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Hall Bend";
  long_desc = "A gentle turn shifts the corridor toward colder air. The floor stones are\nchipped and uneven.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room365", "west",
    "domain/original/area/exedoria/room362", "south",
  });
}
