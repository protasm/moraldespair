inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_6_25", "north",
    "domain/original/area/wilderness/room_8_25", "south",
    "domain/original/area/wilderness/room_7_26", "east",
    "domain/original/area/wilderness/room_7_24", "west",
  });
}
