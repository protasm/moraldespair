inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "North Run";
  long_desc =
    "The road here is uneven, with stones heaved by roots. A bent streetlamp rises\n"
    "from a base of cracked stone.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room260", "south",
    "domain/original/area/anshelm/room265", "north",
  });
}
