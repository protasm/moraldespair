inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room24", "west",
    "chapter/prologue/area/roadway/room26", "east",
    "room/wilderness_room#AI27", "north",
    "room/wilderness_room#AI29", "south",
  });
}
