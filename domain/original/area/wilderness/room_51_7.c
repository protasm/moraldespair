inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_50_7", "north",
    "domain/original/area/wilderness/room_52_7", "south",
    "domain/original/area/wilderness/room_51_8", "east",
    "domain/original/area/wilderness/room_51_6", "west",
  });
}
