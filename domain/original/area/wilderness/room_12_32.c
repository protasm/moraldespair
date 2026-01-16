inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_11_32", "north",
    "domain/original/area/wilderness/room_13_32", "south",
    "domain/original/area/wilderness/room_12_33", "east",
    "domain/original/area/wilderness/room_12_31", "west",
  });
}
