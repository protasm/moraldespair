inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Split Narrow Way";
  long_desc = "Stone underfoot is split into plates, with grit and ash packed into the seams. Walls to either side are chewed by blasts and blade scars, their faces peeled away. The way runs on in a narrow line, hemmed by broken walls left to weather. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1568",
    "south" : "/chapter/prologue/area/dead/room1566",
  ]);

  set_light(1);
}
