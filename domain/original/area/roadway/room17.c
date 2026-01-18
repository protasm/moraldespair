inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "domain/original/area/roadway/room16", "west",
    "domain/original/area/roadway/room18", "east",
    "room/wilderness_room#AA27", "north",
    "room/wilderness_room#AA29", "south",
  });
}
