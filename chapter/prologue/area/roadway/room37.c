inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room36", "south",
    "chapter/prologue/area/roadway/room38", "north",
    "room/wilderness_room#X20", "west",
    "room/wilderness_room#Z20", "east",
  });
}
