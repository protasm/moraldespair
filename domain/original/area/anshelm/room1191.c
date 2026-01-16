inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Empty Bistro";
  long_desc =
    "Small tables have rotted away, leaving only rusted hooks in the floor. A\n"
    "decorative mirror hangs cracked above a cold hearth.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1190", "east",
    "domain/original/area/anshelm/room1185", "south",
  });
}
