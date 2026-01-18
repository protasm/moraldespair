inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "domain/original/area/roadway/room25", "west",
    "domain/original/area/roadway/room27", "east",
    "room/wilderness_room#AJ27", "north",
    "room/wilderness_room#AJ29", "south",
  });
}
