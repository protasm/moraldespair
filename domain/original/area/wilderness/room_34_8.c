inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_33_8", "north",
    "domain/original/area/wilderness/room_35_8", "south",
    "domain/original/area/wilderness/room_34_9", "east",
    "domain/original/area/wilderness/room_34_7", "west",
  });
}
