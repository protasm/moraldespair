inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_27_6", "north",
    "domain/original/area/wilderness/room_29_6", "south",
    "domain/original/area/wilderness/room_28_7", "east",
    "domain/original/area/wilderness/room_28_5", "west",
  });
}
