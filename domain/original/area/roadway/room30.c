inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/ruined/entrance", "south",
    "domain/original/area/roadway/room31", "north",
    "room/wilderness_room#X27", "west",
    "room/wilderness_room#Z27", "east",
  });
}
