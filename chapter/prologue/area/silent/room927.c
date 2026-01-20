inherit "room/room";

void create() {
  ::create();

  short_desc = "Rust Garden";
  long_desc = "Rusting frames and gears sit half swallowed by vines. A path winds between\nthem in silence.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room926", "east",
  });

  set_light(1);
}
