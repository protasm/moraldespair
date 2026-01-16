inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_10_47", "north",
    "domain/original/area/wilderness/room_12_47", "south",
    "domain/original/area/wilderness/room_11_48", "east",
    "domain/original/area/wilderness/room_11_46", "west",
  });
}
