inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Rutted Street";
  long_desc = "Ruts and puddled clay mark the old path between low walls. Scattered rubble\nsuggests a long abandoned block.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room295", "east",
    "domain/original/area/exedoria/room293", "west",
  });
}
