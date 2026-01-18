inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "domain/original/area/roadway/room38", "south",
    "domain/original/area/roadway/room40", "north",
    "room/wilderness_room#X18", "west",
    "room/wilderness_room#Z18", "east",
  });
}
