inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Sunk Narrow Way";
  long_desc = "The ground is a mosaic of cracked slabs and loose grit, dulled by age. Walls to either side are chewed by blasts and blade scars, their faces peeled away. The way runs on in a narrow line, hemmed by broken walls left to weather. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1569",
    "south" : "/chapter/prologue/area/dead/room1567",
  ]);

  set_light(1);
}
