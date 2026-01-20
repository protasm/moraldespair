inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room53", "north",
    "chapter/prologue/area/roadway/room55", "south",
    "room/wilderness_room#X40", "west",
    "room/wilderness_room#Z40", "east",
  });
}
