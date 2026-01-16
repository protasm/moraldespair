inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_12_3", "north",
    "domain/original/area/wilderness/room_14_3", "south",
    "domain/original/area/wilderness/room_13_4", "east",
    "domain/original/area/wilderness/room_13_2", "west",
  });
}
