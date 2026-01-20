inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room26", "west",
    "chapter/prologue/area/roadway/room28", "east",
    "room/wilderness_room#AK27", "north",
    "room/wilderness_room#AK29", "south",
  });
}
