inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_13_22", "north",
    "domain/original/area/wilderness/room_15_22", "south",
    "domain/original/area/wilderness/room_14_23", "east",
    "domain/original/area/wilderness/room_14_21", "west",
  });
}
