inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Chalked Loft";
  long_desc = "A narrow stair ends in a loft where a worktable sits split and furred with\n"
              + "mildew. Blackened candle stubs and cracked lenses lie in drifts of dust,\n"
              + "hinting at old study now drowned in silence and rot.\n";
  dest_dir = ({
    "domain/original/area/vesla/room397", "west",
  });
}
