inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_4_16", "north",
    "domain/original/area/wilderness/room_6_16", "south",
    "domain/original/area/wilderness/room_5_17", "east",
    "domain/original/area/wilderness/room_5_15", "west",
  });
}
