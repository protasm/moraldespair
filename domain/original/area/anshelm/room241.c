inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Broken Row";
  long_desc =
    "Low buildings crowd the street, their doorways gaping and dark. Rainwater\n"
    "gathers in the ruts where carts once passed.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room416", "west",
    "domain/original/area/anshelm/room240", "south",
    "domain/original/area/anshelm/room242", "north",
  });
}
