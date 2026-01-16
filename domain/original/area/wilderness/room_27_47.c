inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_26_47", "north",
    "domain/original/area/wilderness/room_28_47", "south",
    "domain/original/area/wilderness/room_27_48", "east",
    "domain/original/area/wilderness/room_27_46", "west",
  });
}
