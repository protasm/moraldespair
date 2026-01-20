inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Empty Kitchen";
  long_desc = "A small dining room opens into a bare kitchen. The counters are bare and the\nhearth is cold.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room302", "north",
  });
}
