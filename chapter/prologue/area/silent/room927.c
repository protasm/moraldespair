inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Rust Garden";
  long_desc = "Rusting frames and gears sit half swallowed by vines. A path winds between\nthem in silence.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room926", "east",
  });
}
