inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Road End";
  long_desc = "The road narrows and loses its paving in a drift of soil. Beyond it, the track\ndissolves into grass.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room306", "east",
    "domain/original/area/exedoria/room331", "northwest",
    "domain/original/area/exedoria/room308", "south",
  });
}
