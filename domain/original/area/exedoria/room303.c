inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Road Middle";
  long_desc = "The road runs straight between broken foundations. Dust and grit have buried\nthe old curb.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room304", "west",
    "domain/original/area/exedoria/room302", "east",
    "domain/original/area/exedoria/room329", "south",
  });
}
