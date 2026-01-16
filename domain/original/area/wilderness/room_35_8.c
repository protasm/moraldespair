inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_34_8", "north",
    "domain/original/area/wilderness/room_36_8", "south",
    "domain/original/area/wilderness/room_35_9", "east",
    "domain/original/area/wilderness/room_35_7", "west",
  });
}
