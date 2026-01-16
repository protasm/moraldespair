inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_45_43", "north",
    "domain/original/area/wilderness/room_47_43", "south",
    "domain/original/area/wilderness/room_46_44", "east",
    "domain/original/area/wilderness/room_46_42", "west",
  });
}
