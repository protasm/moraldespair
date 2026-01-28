inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Lichen Narrow Way";
  long_desc = "The ground is a mosaic of cracked slabs and loose grit, dulled by age. Blackened streaks and gouges run along the masonry, breaking any clean line. The way runs on in a narrow line, hemmed by broken walls left to weather. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "east" : "/chapter/prologue/area/dead/room1584",
    "west" : "/chapter/prologue/area/dead/room1589",
  ]);

  set_light(1);
}
