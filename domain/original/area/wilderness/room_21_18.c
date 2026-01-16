inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_20_18", "north",
    "domain/original/area/wilderness/room_22_18", "south",
    "domain/original/area/wilderness/room_21_19", "east",
    "domain/original/area/wilderness/room_21_17", "west",
  });
}
