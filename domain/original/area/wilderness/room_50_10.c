inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_49_10", "north",
    "domain/original/area/wilderness/room_51_10", "south",
    "domain/original/area/wilderness/room_50_11", "east",
    "domain/original/area/wilderness/room_50_9", "west",
  });
}
