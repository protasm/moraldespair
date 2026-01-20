inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room60", "west",
    "chapter/prologue/area/silent/entrance", "east",
    "room/wilderness_room#AR27", "north",
    "room/wilderness_room#AR29", "south",
  });
}
