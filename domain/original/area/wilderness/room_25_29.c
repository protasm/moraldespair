inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_24_29", "north",
    "domain/original/area/wilderness/room_26_29", "south",
    "domain/original/area/wilderness/room_25_30", "east",
    "domain/original/area/wilderness/room_25_28", "west",
  });
}
