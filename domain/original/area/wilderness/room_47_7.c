inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_46_7", "north",
    "domain/original/area/wilderness/room_48_7", "south",
    "domain/original/area/wilderness/room_47_8", "east",
    "domain/original/area/wilderness/room_47_6", "west",
  });
}
