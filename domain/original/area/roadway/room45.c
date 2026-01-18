inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "domain/original/area/roadway/room44", "north",
    "domain/original/area/roadway/room46", "south",
    "room/wilderness_room#X31", "west",
    "room/wilderness_room#Z31", "east",
  });
}
