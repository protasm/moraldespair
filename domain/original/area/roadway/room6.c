inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "domain/original/area/roadway/room5", "west",
    "domain/original/area/roadway/room7", "east",
    "room/wilderness_room#Q27", "north",
    "room/wilderness_room#Q29", "south",
  });
}
