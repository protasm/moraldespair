inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_3_5", "north",
    "domain/original/area/wilderness/room_5_5", "south",
    "domain/original/area/wilderness/room_4_6", "east",
    "domain/original/area/wilderness/room_4_4", "west",
  });
}
