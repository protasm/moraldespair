inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Stone Street";
  long_desc = "A straight street runs between low walls and empty storefronts. Loose grit\ncrunches over the paving.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room336", "east",
    "domain/original/area/exedoria/room334", "west",
  });
}
