inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_14_2", "north",
    "domain/original/area/wilderness/room_16_2", "south",
    "domain/original/area/wilderness/room_15_3", "east",
    "domain/original/area/wilderness/room_15_1", "west",
  });
}
