inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Lichen Narrow Way";
  long_desc = "Loose stones shift underfoot, buried in silt and powdered mortar. Leaning walls show long cuts and scorch trails, as if steel and heat worried them for hours. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "east" : "/chapter/prologue/area/dead/room1416",
    "west" : "/chapter/prologue/area/dead/room1418",
  ]);

  set_light(1);
}
