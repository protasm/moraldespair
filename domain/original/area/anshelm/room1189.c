inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "East Avenue";
  long_desc =
    "The street widens near a cluster of fallen columns and brick. Dried vines lace\n"
    "across the cracked masonry.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1188", "west",
  });
}
