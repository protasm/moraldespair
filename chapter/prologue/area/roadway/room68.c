inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room67", "south",
    "domain/original/area/anshelm/entrance", "north",
    "room/wilderness_room#X8", "west",
    "room/wilderness_room#Z8", "east",
  });
}
