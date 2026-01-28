inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Choked Faded Narrow Way";
  long_desc = "Grit and broken tiles lie in drifts, the ground uneven and tired. Fragments of arches and lintels hang at odd angles, cut and burned through. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1507",
    "south" : "/chapter/prologue/area/dead/room1418",
  ]);

  set_light(1);
}
