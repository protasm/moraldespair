inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_24_13", "north",
    "domain/original/area/wilderness/room_26_13", "south",
    "domain/original/area/wilderness/room_25_14", "east",
    "domain/original/area/wilderness/room_25_12", "west",
  });
}
