inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Flagstone Entry";
  long_desc = "Flat stones form a short entry that has sunk into the ground. Weeds push\nthrough every seam.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room915", "south",
    "chapter/prologue/area/silent/room337", "north",
  });
}
