inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_23_46", "north",
    "domain/original/area/wilderness/room_25_46", "south",
    "domain/original/area/wilderness/room_24_47", "east",
    "domain/original/area/wilderness/room_24_45", "west",
  });
}
