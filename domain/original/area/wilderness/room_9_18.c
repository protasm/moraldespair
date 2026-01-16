inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_8_18", "north",
    "domain/original/area/wilderness/room_10_18", "south",
    "domain/original/area/wilderness/room_9_19", "east",
    "domain/original/area/wilderness/room_9_17", "west",
  });
}
