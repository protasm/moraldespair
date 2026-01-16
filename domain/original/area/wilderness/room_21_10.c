inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_20_10", "north",
    "domain/original/area/wilderness/room_22_10", "south",
    "domain/original/area/wilderness/room_21_11", "east",
    "domain/original/area/wilderness/room_21_9", "west",
  });
}
