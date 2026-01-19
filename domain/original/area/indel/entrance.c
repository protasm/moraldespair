inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "City of the Dead";
  long_desc = "A city overtaken by the dead.";
  dest_dir = ({
    "domain/original/area/roadway/room71", "north",
    "room/wilderness_room#X45", "west",
    "room/wilderness_room#Z45", "east",
    "room/wilderness_room#Y46", "south",
    "domain/original/area/indel/room1401", "city",
  });

  add_exit_alias("c", "city");
}
