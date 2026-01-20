inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Broken Road";
  long_desc = "A broad road runs between fractured curbstones and toppled markers. The center\nis worn smooth where traffic once passed.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room301", "south",
    "chapter/prologue/area/silent/room302", "west",
    "chapter/prologue/area/silent/room385", "east",
    "chapter/prologue/area/silent/room299", "north",
  });
}
