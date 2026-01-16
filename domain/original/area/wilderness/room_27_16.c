inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_26_16", "north",
    "domain/original/area/wilderness/room_28_16", "south",
    "domain/original/area/wilderness/room_27_17", "east",
    "domain/original/area/wilderness/room_27_15", "west",
  });
}
