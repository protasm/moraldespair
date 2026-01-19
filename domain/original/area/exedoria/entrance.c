inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Silent City";
  long_desc = "A graveyard where a city once thrived.";
  dest_dir = ({
    "domain/original/area/roadway/room61", "west",
    "room/wilderness_room#AS27", "north",
    "room/wilderness_room#AT28", "east",
    "room/wilderness_room#AS29", "south",
    "domain/original/area/exedoria/room286", "city",
  });

  add_exit_alias("c", "city");
}

