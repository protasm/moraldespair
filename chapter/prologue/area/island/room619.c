inherit "room/room";

void create() {
  ::create();


  short_desc = "End of Silver Street";
  long_desc =  "The pale stones of Silver Street terminate at the jagged base of a\n" +
    "mountainous peak. Thick, rhythmic plumes of soot and dull flame rise\n" +
    "from the summit, casting a heavy shroud over the valley. Along the high\n" +
    "ridges, dark silhouettes of orcish sentinels remain motionless against\n" +
    "the gray sky, their gaze fixed eternally upon the vacant streets below.\n" +
    "A silent storefront stands to the east, while a stone facade blocks the\n" +
    "view to the west.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/island/room620",
    "south" : "/chapter/prologue/area/island/room618",
  ]);

  set_light(1);
}
