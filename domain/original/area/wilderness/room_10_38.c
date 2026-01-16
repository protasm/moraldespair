inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_9_38", "north",
    "domain/original/area/wilderness/room_11_38", "south",
    "domain/original/area/wilderness/room_10_39", "east",
    "domain/original/area/wilderness/room_10_37", "west",
  });
}
