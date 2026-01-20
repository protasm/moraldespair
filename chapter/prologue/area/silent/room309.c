inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Narrow Lane";
  long_desc = "A narrow lane winds between close houses with shuttered windows. Damp stains\nstripe the stone.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room310", "south",
    "chapter/prologue/area/silent/room308", "north",
  });
}
