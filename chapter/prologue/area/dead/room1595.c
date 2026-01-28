inherit "/room/room";

void create() {
  ::create();

  short_desc = "Cold Narrow Way";
  long_desc = "Pitted stone stretches ahead, littered with chips and fragments. Blackened streaks and gouges run along the masonry, breaking any clean line. The way runs on in a narrow line, hemmed by broken walls left to weather. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "east" : "/chapter/prologue/area/dead/room1594",
    "west" : "/chapter/prologue/area/dead/room1596",
  ]);

  set_light(1);
}
