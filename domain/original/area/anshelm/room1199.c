inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Old Smithy";
  long_desc =
    "A low shack of stone holds a cold forge and a broken anvil. Rust flakes\n"
    "glitter across the hearth.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room270", "north",
  });
}
