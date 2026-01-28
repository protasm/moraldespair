inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Eroded Narrow Way";
  long_desc = "The floor is a churn of fractured stone and rubble, pressed flat by time. Leaning walls show long cuts and scorch trails, as if steel and heat worried them for hours. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "east" : "/chapter/prologue/area/dead/room1413",
    "west" : "/chapter/prologue/area/dead/room1415",
  ]);

  set_light(1);
}
