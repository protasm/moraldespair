inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_42_10", "north",
    "domain/original/area/wilderness/room_44_10", "south",
    "domain/original/area/wilderness/room_43_11", "east",
    "domain/original/area/wilderness/room_43_9", "west",
  });
}
