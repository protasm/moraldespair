inherit "/room/room";

void create() {
  ::create();

  short_desc = "Shattered Bleached Narrow Way";
  long_desc = "The surface dips and rises where blocks have settled, leaving sharp lips and hollows. Leaning walls show long cuts and scorch trails, as if steel and heat worried them for hours. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "east" : "/chapter/prologue/area/dead/room1415",
    "west" : "/chapter/prologue/area/dead/room1417",
  ]);

  set_light(1);
}
