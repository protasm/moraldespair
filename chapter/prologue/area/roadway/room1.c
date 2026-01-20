inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/sunken/entrance", "west",
    "chapter/prologue/area/roadway/room2", "east",
    "room/wilderness_room#L27", "north",
    "room/wilderness_room#L29", "south",
  });
}
