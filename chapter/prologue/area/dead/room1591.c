inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Stained Narrow Way";
  long_desc = "Rubble and crushed mortar blanket the surface, slick in places with old damp. Blackened streaks and gouges run along the masonry, breaking any clean line. The way runs on in a narrow line, hemmed by broken walls left to weather. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "east" : "/chapter/prologue/area/dead/room1592",
    "west" : "/chapter/prologue/area/dead/room1542",
  ]);

  set_light(1);
}
