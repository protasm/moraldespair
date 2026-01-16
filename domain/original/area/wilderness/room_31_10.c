inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_30_10", "north",
    "domain/original/area/wilderness/room_32_10", "south",
    "domain/original/area/wilderness/room_31_11", "east",
    "domain/original/area/wilderness/room_31_9", "west",
  });
}
