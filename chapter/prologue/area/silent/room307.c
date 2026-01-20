inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Road End";
  long_desc = "The road narrows and loses its paving in a drift of soil. Beyond it, the track\ndissolves into grass.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room306", "east",
    "chapter/prologue/area/silent/room331", "northwest",
    "chapter/prologue/area/silent/room308", "south",
  });
}
