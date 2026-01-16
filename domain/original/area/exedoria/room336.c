inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Stone Street";
  long_desc = "The street here is broad, its stones worn smooth in places. Small piles of\nrubble mark fallen doorways.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room335", "west",
    "domain/original/area/exedoria/room337", "east",
    "domain/original/area/exedoria/room602", "north",
  });
}
