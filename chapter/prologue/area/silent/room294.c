inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Rutted Street";
  long_desc = "Ruts and puddled clay mark the old path between low walls. Scattered rubble\nsuggests a long abandoned block.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room295", "east",
    "chapter/prologue/area/silent/room293", "west",
  });
}
