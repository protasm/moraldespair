inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_23_31", "north",
    "domain/original/area/wilderness/room_25_31", "south",
    "domain/original/area/wilderness/room_24_32", "east",
    "domain/original/area/wilderness/room_24_30", "west",
  });
}
