inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Sunken City";
  long_desc = "Once a city, now swallowed by the desert.";
  dest_dir = ({
    "chapter/prologue/area/roadway/room1", "east",
    "room/wilderness_room#K27", "north",
    "room/wilderness_room#K29", "south",
    "room/wilderness_room#J28", "west",
    "chapter/prologue/area/sunken/room1", "city",
  });

  add_exit_alias("c", "city");
}
