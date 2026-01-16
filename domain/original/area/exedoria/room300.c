inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Broken Road";
  long_desc = "A broad road runs between fractured curbstones and toppled markers. The center\nis worn smooth where traffic once passed.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room301", "south",
    "domain/original/area/exedoria/room302", "west",
    "domain/original/area/exedoria/room385", "east",
    "domain/original/area/exedoria/room299", "north",
  });
}
