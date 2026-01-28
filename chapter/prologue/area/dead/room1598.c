inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Cold Split Way";
  long_desc = "The ground is a mosaic of cracked slabs and loose grit, dulled by age. Fragments of arches and lintels hang at odd angles, cut and burned through. The path splits around a heap of fallen blocks, offering lines gone to ruin. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1599",
    "south" : "/chapter/prologue/area/dead/room1597",
    "east" : "/chapter/prologue/area/dead/room1600",
  ]);

  set_light(1);
}
