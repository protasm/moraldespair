inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_11_48", "north",
    "domain/original/area/wilderness/room_13_48", "south",
    "domain/original/area/wilderness/room_12_49", "east",
    "domain/original/area/wilderness/room_12_47", "west",
  });
}
