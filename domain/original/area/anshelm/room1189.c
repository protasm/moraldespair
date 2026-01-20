inherit "room/room";

void create() {
  ::create();

  short_desc = "East Avenue";
  long_desc =
    "The street widens near a cluster of fallen columns and brick. Dried vines lace\n"
    "across the cracked masonry.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1188", "west",
  });

  set_light(1);
}
