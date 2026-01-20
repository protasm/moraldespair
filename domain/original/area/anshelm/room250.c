inherit "room/room";

void create() {
  ::create();

  short_desc = "East Crossing";
  long_desc =
    "The street opens to a small intersection marked by worn corner stones. Broken\n"
    "shutters hang from a nearby window frame.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room244", "west",
    "domain/original/area/anshelm/room283", "east",
    "domain/original/area/anshelm/room251", "north",
  });

  set_light(1);
}
