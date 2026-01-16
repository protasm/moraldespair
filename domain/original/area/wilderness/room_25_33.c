inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_24_33", "north",
    "domain/original/area/wilderness/room_26_33", "south",
    "domain/original/area/wilderness/room_25_34", "east",
    "domain/original/area/wilderness/room_25_32", "west",
  });
}
