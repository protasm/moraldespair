inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_9_49", "north",
    "domain/original/area/wilderness/room_11_49", "south",
    "domain/original/area/wilderness/room_10_50", "east",
    "domain/original/area/wilderness/room_10_48", "west",
  });
}
