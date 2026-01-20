inherit "room/room";

void create() {
  ::create();

  short_desc = "East Crossing";
  long_desc =
    "The street opens to a small intersection marked by worn corner stones. Broken\n"
    "shutters hang from a nearby window frame.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room244", "west",
    "chapter/prologue/area/anshelm/room283", "east",
    "chapter/prologue/area/anshelm/room251", "north",
  });

  set_light(1);
}
