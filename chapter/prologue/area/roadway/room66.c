inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room65", "south",
    "chapter/prologue/area/roadway/room67", "north",
    "room/wilderness_room#X10", "west",
    "room/wilderness_room#Z10", "east",
  });
}
