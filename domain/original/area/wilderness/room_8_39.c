inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_7_39", "north",
    "domain/original/area/wilderness/room_9_39", "south",
    "domain/original/area/wilderness/room_8_40", "east",
    "domain/original/area/wilderness/room_8_38", "west",
  });
}
