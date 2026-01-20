inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Steward Office";
  long_desc = "A narrow office holds a broken chair and a faded ledger. The walls are stained\nwhere lamps once burned.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room894", "south",
  });
}
