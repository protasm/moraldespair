inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_3_12", "north",
    "domain/original/area/wilderness/room_5_12", "south",
    "domain/original/area/wilderness/room_4_13", "east",
    "domain/original/area/wilderness/room_4_11", "west",
  });
}
