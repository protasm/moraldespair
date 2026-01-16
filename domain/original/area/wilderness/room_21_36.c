inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_20_36", "north",
    "domain/original/area/wilderness/room_22_36", "south",
    "domain/original/area/wilderness/room_21_37", "east",
    "domain/original/area/wilderness/room_21_35", "west",
  });
}
