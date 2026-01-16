inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_48_4", "north",
    "domain/original/area/wilderness/room_50_4", "south",
    "domain/original/area/wilderness/room_49_5", "east",
    "domain/original/area/wilderness/room_49_3", "west",
  });
}
