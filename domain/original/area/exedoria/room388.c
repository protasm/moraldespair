inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Quiet Walk";
  long_desc = "A narrower walk skirts a line of study halls. The stones are uneven and\nspotted with moss.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room389", "east",
    "domain/original/area/exedoria/room387", "west",
  });
}
