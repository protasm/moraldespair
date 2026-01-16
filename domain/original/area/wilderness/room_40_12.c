inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_39_12", "north",
    "domain/original/area/wilderness/room_41_12", "south",
    "domain/original/area/wilderness/room_40_13", "east",
    "domain/original/area/wilderness/room_40_11", "west",
  });
}
