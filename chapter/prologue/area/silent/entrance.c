inherit "room/room";

void create() {
  ::create();

  short_desc = "Silent City";
  long_desc = "An open grave where a small city once thrived.";
  dest_dir = ({
    "domain/original/area/roadway/room61", "west",
    "room/wilderness_room#AS27", "north",
    "room/wilderness_room#AT28", "east",
    "room/wilderness_room#AS29", "south",
    "chapter/prologue/area/silent/room286", "city",
  });

  add_exit_alias("c", "city");

  set_light(1);
}


