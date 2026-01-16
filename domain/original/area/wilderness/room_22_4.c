inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_21_4", "north",
    "domain/original/area/wilderness/room_23_4", "south",
    "domain/original/area/wilderness/room_22_5", "east",
    "domain/original/area/wilderness/room_22_3", "west",
  });
}
