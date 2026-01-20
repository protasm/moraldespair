inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Old Plaza";
  long_desc = "A small plaza opens between low buildings, its paving split by weeds. A dry\nfountain basin lies cracked at its center.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room300", "south",
    "chapter/prologue/area/silent/room290", "north",
  });
}
