inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "domain/original/area/roadway/room64", "south",
    "domain/original/area/roadway/room66", "north",
    "room/wilderness_room#X11", "west",
    "room/wilderness_room#Z11", "east",
  });
}
