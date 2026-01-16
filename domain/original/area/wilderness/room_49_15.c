inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_48_15", "north",
    "domain/original/area/wilderness/room_50_15", "south",
    "domain/original/area/wilderness/room_49_16", "east",
    "domain/original/area/wilderness/room_49_14", "west",
  });
}
