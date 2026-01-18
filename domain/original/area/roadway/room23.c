inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "domain/original/area/roadway/room22", "west",
    "domain/original/area/roadway/room24", "east",
    "room/wilderness_room#AG27", "north",
    "room/wilderness_room#AG29", "south",
  });
}
