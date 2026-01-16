inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_49_14", "north",
    "domain/original/area/wilderness/room_51_14", "south",
    "domain/original/area/wilderness/room_50_15", "east",
    "domain/original/area/wilderness/room_50_13", "west",
  });
}
