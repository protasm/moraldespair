inherit "room/room";

void create() {
  ::create();

  short_desc = "Ashen Narrow Way";
  long_desc = "Stone underfoot is split into plates, with grit and ash packed into the seams. Leaning walls show long cuts and scorch trails, as if steel and heat worried them for hours. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "east" : "/chapter/prologue/area/dead/room1410",
    "west" : "/chapter/prologue/area/dead/room1412",
  ]);

  set_light(1);
}
