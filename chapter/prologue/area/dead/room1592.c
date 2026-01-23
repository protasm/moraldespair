inherit "room/room";

void create() {
  ::create();

  short_desc = "Cold Narrow Way";
  long_desc = "The surface dips and rises where blocks have settled, leaving sharp lips and hollows. Blackened streaks and gouges run along the masonry, breaking any clean line. The way runs on in a narrow line, hemmed by broken walls left to weather. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "east" : "/chapter/prologue/area/dead/room1593",
    "west" : "/chapter/prologue/area/dead/room1591",
  ]);

  set_light(1);
}
