inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Quiet Walk";
  long_desc = "A narrower walk skirts a line of study halls. The stones are uneven and\nspotted with moss.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room389", "east",
    "chapter/prologue/area/silent/room387", "west",
  });
}
