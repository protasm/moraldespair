inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "East Bridge";
  long_desc = "A narrow stone bridge spans a shallow, weed-choked channel. Several stones are\nmissing, leaving gaps that show the water below.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room337", "west",
    "chapter/prologue/area/silent/room339", "east",
    "chapter/prologue/area/silent/room604", "north",
  });
}
