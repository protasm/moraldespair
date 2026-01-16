inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "East Crossing";
  long_desc =
    "The street opens to a small intersection marked by worn corner stones. Broken\n"
    "shutters hang from a nearby window frame.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room244", "west",
    "domain/original/area/anshelm/room283", "east",
    "domain/original/area/anshelm/room251", "north",
  });
}
