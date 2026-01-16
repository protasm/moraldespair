inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_45_25", "north",
    "domain/original/area/wilderness/room_47_25", "south",
    "domain/original/area/wilderness/room_46_26", "east",
    "domain/original/area/wilderness/room_46_24", "west",
  });
}
