inherit "room/room";

void create() {
  ::create();

  short_desc = "Mossy Cold Narrow Way";
  long_desc = "Pitted stone stretches ahead, littered with chips and fragments. Walls to either side are chewed by blasts and blade scars, their faces peeled away. The way runs on in a narrow line, hemmed by broken walls left to weather. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "east" : "/chapter/prologue/area/dead/room1576",
    "west" : "/chapter/prologue/area/dead/room1574",
  ]);

  set_light(1);
}
