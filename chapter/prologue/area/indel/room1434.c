inherit "room/room";

void create() {
  ::create();

  short_desc = "Smeared Bleached Split Way";
  long_desc = "The floor is a churn of fractured stone and rubble, pressed flat by time. Fragments of arches and lintels hang at odd angles, cut and burned through. The path splits around a heap of fallen blocks, offering lines gone to ruin. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ({
    "chapter/prologue/area/indel/room1433", "north",
    "chapter/prologue/area/indel/room1435", "south",
    "chapter/prologue/area/indel/room1545", "east",
  });

  set_light(1);
}
