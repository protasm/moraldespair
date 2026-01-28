inherit "/room/room";

void create() {
  ::create();

  short_desc = "Pitted Cold Broken Bend";
  long_desc = "The floor is a churn of fractured stone and rubble, pressed flat by time. Blackened streaks and gouges run along the masonry, breaking any clean line. The passage angles hard here, squeezed between stone left to lean and settle. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1409",
    "east" : "/chapter/prologue/area/dead/room1589",
  ]);

  set_light(1);
}
