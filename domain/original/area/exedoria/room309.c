inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Narrow Lane";
  long_desc = "A narrow lane winds between close houses with shuttered windows. Damp stains\nstripe the stone.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room310", "south",
    "domain/original/area/exedoria/room308", "north",
  });
}
