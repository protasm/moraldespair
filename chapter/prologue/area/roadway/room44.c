inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room43", "north",
    "chapter/prologue/area/roadway/room45", "south",
    "room/wilderness_room#X30", "west",
    "room/wilderness_room#Z30", "east",
  });
}
