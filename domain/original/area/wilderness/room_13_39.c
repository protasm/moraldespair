inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_12_39", "north",
    "domain/original/area/wilderness/room_14_39", "south",
    "domain/original/area/wilderness/room_13_40", "east",
    "domain/original/area/wilderness/room_13_38", "west",
  });
}
