inherit "room/room";

void create() {
  ::create();

  short_desc = "Broken Threshold";
  long_desc = "A wide threshold of cracked stone leads into a cavernous hall, its pillars pocked and green with mildew. Shattered bowls lie at the base of a raised dais, and ash-dark banners hang in ragged silence.";
  dest_dir = ([
    "east":"/chapter/prologue/area/ruined/room404",
    "west":"/chapter/prologue/area/ruined/room216",
  ]);

  set_light(1);
}
