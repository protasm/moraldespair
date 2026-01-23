inherit "room/room";

void create() {
  ::create();

  short_desc = "Broken Cold Narrow Way";
  long_desc = "The surface dips and rises where blocks have settled, leaving sharp lips and hollows. Walls to either side are chewed by blasts and blade scars, their faces peeled away. The way runs on in a narrow line, hemmed by broken walls left to weather. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "east" : "/chapter/prologue/area/indel/room1573",
    "west" : "/chapter/prologue/area/indel/room1571",
  ]);

  set_light(1);
}
