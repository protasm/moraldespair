inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_31_31", "north",
    "domain/original/area/wilderness/room_33_31", "south",
    "domain/original/area/wilderness/room_32_32", "east",
    "domain/original/area/wilderness/room_32_30", "west",
  });
}
