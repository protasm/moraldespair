inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_22_5", "north",
    "domain/original/area/wilderness/room_24_5", "south",
    "domain/original/area/wilderness/room_23_6", "east",
    "domain/original/area/wilderness/room_23_4", "west",
  });
}
