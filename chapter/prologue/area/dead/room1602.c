inherit "room/room";

void create() {
  ::create();

  short_desc = "Split Cold Broken Bend";
  long_desc = "The surface dips and rises where blocks have settled, leaving sharp lips and hollows. Fragments of arches and lintels hang at odd angles, cut and burned through. The passage angles hard here, squeezed between stone left to lean and settle. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1600",
    "east" : "/chapter/prologue/area/dead/room1605",
  ]);

  set_light(1);
}
