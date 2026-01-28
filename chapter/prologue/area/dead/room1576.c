inherit "/room/room";

void create() {
  ::create();

  short_desc = "Choked Narrow Way";
  long_desc = "Grit and broken tiles lie in drifts, the ground uneven and tired. Walls to either side are chewed by blasts and blade scars, their faces peeled away. The way runs on in a narrow line, hemmed by broken walls left to weather. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "east" : "/chapter/prologue/area/dead/room1577",
    "west" : "/chapter/prologue/area/dead/room1575",
  ]);

  set_light(1);
}
