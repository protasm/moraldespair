inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_19_10", "north",
    "domain/original/area/wilderness/room_21_10", "south",
    "domain/original/area/wilderness/room_20_11", "east",
    "domain/original/area/wilderness/room_20_9", "west",
  });
}
