inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_49_4", "north",
    "domain/original/area/wilderness/room_51_4", "south",
    "domain/original/area/wilderness/room_50_5", "east",
    "domain/original/area/wilderness/room_50_3", "west",
  });
}
