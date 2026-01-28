inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Slick Split Way";
  long_desc = "Stone underfoot is split into plates, with grit and ash packed into the seams. Fragments of arches and lintels hang at odd angles, cut and burned through. The path splits around a heap of fallen blocks, offering lines gone to ruin. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1598",
    "south" : "/chapter/prologue/area/dead/room1596",
    "west" : "/chapter/prologue/area/dead/room1533",
  ]);

  set_light(1);
}
