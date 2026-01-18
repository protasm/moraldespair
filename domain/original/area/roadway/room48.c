inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "domain/original/area/roadway/room47", "north",
    "domain/original/area/roadway/room49", "south",
    "room/wilderness_room#X34", "west",
    "room/wilderness_room#Z34", "east",
  });
}
