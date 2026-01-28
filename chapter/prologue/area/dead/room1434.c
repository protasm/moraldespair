inherit "/room/room";

void create() {
  ::create();

  short_desc = "Smeared Bleached Split Way";
  long_desc = "The floor is a churn of fractured stone and rubble, pressed flat by time. Fragments of arches and lintels hang at odd angles, cut and burned through. The path splits around a heap of fallen blocks, offering lines gone to ruin. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1433",
    "south" : "/chapter/prologue/area/dead/room1435",
    "east" : "/chapter/prologue/area/dead/room1545",
  ]);

  set_light(1);
}
