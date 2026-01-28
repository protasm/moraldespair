inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Silent City";
  long_desc = "An open grave where a small city once thrived.";
  dest_dir = ([
    "west":"/chapter/prologue/area/roadway/room61",
    "north":"/room/wilderness_room#AS27",
    "east":"/room/wilderness_room#AT28",
    "south":"/room/wilderness_room#AS29",
    "city":"/chapter/prologue/area/silent/room286",
  ]);

  add_exit_alias("c", "city");

  set_light(1);
}


