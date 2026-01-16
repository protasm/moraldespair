inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_26_4", "north",
    "domain/original/area/wilderness/room_28_4", "south",
    "domain/original/area/wilderness/room_27_5", "east",
    "domain/original/area/wilderness/room_27_3", "west",
  });
}
