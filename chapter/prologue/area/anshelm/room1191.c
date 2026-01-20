inherit "room/room";

void create() {
  ::create();

  short_desc = "Empty Bistro";
  long_desc =
    "Small tables have rotted away, leaving only rusted hooks in the floor. A\n"
    "decorative mirror hangs cracked above a cold hearth.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room1190", "east",
    "chapter/prologue/area/anshelm/room1185", "south",
  });

  set_light(1);
}
