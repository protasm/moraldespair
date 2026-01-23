inherit "room/room";

void create() {
  ::create();

  short_desc = "Bleached Narrow Way";
  long_desc = "The floor is a churn of fractured stone and rubble, pressed flat by time. Blackened streaks and gouges run along the masonry, breaking any clean line. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/indel/room1423",
    "south" : "/chapter/prologue/area/indel/room1425",
  ]);

  set_light(1);
}
