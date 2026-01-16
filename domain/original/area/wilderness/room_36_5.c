inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_35_5", "north",
    "domain/original/area/wilderness/room_37_5", "south",
    "domain/original/area/wilderness/room_36_6", "east",
    "domain/original/area/wilderness/room_36_4", "west",
  });
}
