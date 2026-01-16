inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Old Plaza";
  long_desc = "A small plaza opens between low buildings, its paving split by weeds. A dry\nfountain basin lies cracked at its center.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room300", "south",
    "domain/original/area/exedoria/room290", "north",
  });
}
