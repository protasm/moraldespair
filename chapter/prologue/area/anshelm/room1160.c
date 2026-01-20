inherit "room/room";

void create() {
  ::create();

  short_desc = "Small Chamber";
  long_desc =
    "A small chamber opens off the stair, bare and silent. A broken latch hangs\n"
    "from the doorframe.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room1159", "east",
    "chapter/prologue/area/anshelm/room1161", "west",
  });

  set_light(1);
}
