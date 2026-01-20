inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Road Middle";
  long_desc = "The road runs straight between broken foundations. Dust and grit have buried\nthe old curb.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room304", "west",
    "chapter/prologue/area/silent/room302", "east",
    "chapter/prologue/area/silent/room329", "south",
  });
}
