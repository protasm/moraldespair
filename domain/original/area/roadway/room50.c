inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "domain/original/area/roadway/room49", "north",
    "domain/original/area/roadway/room51", "south",
    "room/wilderness_room#X36", "west",
    "room/wilderness_room#Z36", "east",
  });
}
