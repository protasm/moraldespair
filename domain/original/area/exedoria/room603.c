inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Flagstone Entry";
  long_desc = "Flat stones form a short entry that has sunk into the ground. Weeds push\nthrough every seam.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room915", "south",
    "domain/original/area/exedoria/room337", "north",
  });
}
