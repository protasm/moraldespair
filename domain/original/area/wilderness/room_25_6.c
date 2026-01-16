inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_24_6", "north",
    "domain/original/area/wilderness/room_26_6", "south",
    "domain/original/area/wilderness/room_25_7", "east",
    "domain/original/area/wilderness/room_25_5", "west",
  });
}
