inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "domain/original/area/vesla/entrance", "north",
    "domain/original/area/roadway/room44", "south",
    "room/wilderness_room#X29", "west",
    "room/wilderness_room#Z29", "east",
  });
}
