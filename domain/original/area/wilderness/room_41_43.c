inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_40_43", "north",
    "domain/original/area/wilderness/room_42_43", "south",
    "domain/original/area/wilderness/room_41_44", "east",
    "domain/original/area/wilderness/room_41_42", "west",
  });
}
