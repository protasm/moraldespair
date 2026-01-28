inherit "/room/room";

void create() {
  ::create();

  short_desc = "Slick Faded Narrow Way";
  long_desc = "Stone underfoot is split into plates, with grit and ash packed into the seams. The stonework is torn open, exposing fill and roots, with scorch marks in the cracks. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1526",
    "south" : "/chapter/prologue/area/dead/room1528",
  ]);

  set_light(1);
}
