inherit "room/room";

void create() {
  ::create();

  short_desc = "Rutted Street";
  long_desc = "Ruts and puddled clay mark the old path between low walls. Scattered rubble\nsuggests a long abandoned block.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room295", "east",
    "chapter/prologue/area/silent/room293", "west",
  });

  set_light(1);
}
