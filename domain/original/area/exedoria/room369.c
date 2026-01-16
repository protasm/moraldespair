inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Silent Board";
  long_desc = "A weathered board stands against the wall, its notices long since torn away.\nRusted nails hold scraps of curled parchment.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room290", "south",
  });
}
