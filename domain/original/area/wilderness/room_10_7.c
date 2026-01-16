inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_9_7", "north",
    "domain/original/area/wilderness/room_11_7", "south",
    "domain/original/area/wilderness/room_10_8", "east",
    "domain/original/area/wilderness/room_10_6", "west",
  });
}
