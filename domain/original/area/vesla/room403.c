inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Broken Threshold";
  long_desc = "A wide threshold of cracked stone leads into a cavernous hall, its pillars\n"
              + "pocked and green with mildew. Shattered bowls lie at the base of a raised\n"
              + "dais, and ash-dark banners hang in ragged silence.\n";
  dest_dir = ({
    "domain/original/area/vesla/room404", "east",
    "domain/original/area/vesla/room216", "west",
  });
}
