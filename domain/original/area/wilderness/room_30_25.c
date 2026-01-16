inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_29_25", "north",
    "domain/original/area/wilderness/room_31_25", "south",
    "domain/original/area/wilderness/room_30_26", "east",
    "domain/original/area/wilderness/room_30_24", "west",
  });
}
