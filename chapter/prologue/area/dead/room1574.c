inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Cold Narrow Way";
  long_desc = "Split slabs tilt against each other, their edges worn to chalk. Walls to either side are chewed by blasts and blade scars, their faces peeled away. The way runs on in a narrow line, hemmed by broken walls left to weather. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "east" : "/chapter/prologue/area/dead/room1575",
    "west" : "/chapter/prologue/area/dead/room1573",
  ]);

  set_light(1);
}
