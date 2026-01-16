inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_14_48", "north",
    "domain/original/area/wilderness/room_16_48", "south",
    "domain/original/area/wilderness/room_15_49", "east",
    "domain/original/area/wilderness/room_15_47", "west",
  });
}
