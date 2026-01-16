inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_6_14", "north",
    "domain/original/area/wilderness/room_8_14", "south",
    "domain/original/area/wilderness/room_7_15", "east",
    "domain/original/area/wilderness/room_7_13", "west",
  });
}
