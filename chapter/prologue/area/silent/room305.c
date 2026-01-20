inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Broken Road";
  long_desc = "A long stretch of road lies quiet under a thin scatter of leaves. The gutters\nare choked with soil and moss.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room306", "west",
    "chapter/prologue/area/silent/room304", "east",
    "chapter/prologue/area/silent/room393", "north",
  });
}
