inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_48_20", "north",
    "domain/original/area/wilderness/room_50_20", "south",
    "domain/original/area/wilderness/room_49_21", "east",
    "domain/original/area/wilderness/room_49_19", "west",
  });
}
