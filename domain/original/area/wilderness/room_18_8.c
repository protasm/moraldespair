inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_17_8", "north",
    "domain/original/area/wilderness/room_19_8", "south",
    "domain/original/area/wilderness/room_18_9", "east",
    "domain/original/area/wilderness/room_18_7", "west",
  });
}
