inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Broken Road";
  long_desc = "A long stretch of road lies quiet under a thin scatter of leaves. The gutters\nare choked with soil and moss.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room306", "west",
    "domain/original/area/exedoria/room304", "east",
    "domain/original/area/exedoria/room393", "north",
  });
}
