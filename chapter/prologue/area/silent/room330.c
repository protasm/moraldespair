inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Sealed Hall";
  long_desc = "A heavy door and shuttered windows mark a hall that was once important. The\nsign above the entrance hangs broken and unreadable.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room304", "south",
    "chapter/prologue/area/silent/room287", "north",
  });
}
