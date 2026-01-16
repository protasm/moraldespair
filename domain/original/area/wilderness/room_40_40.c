inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_39_40", "north",
    "domain/original/area/wilderness/room_41_40", "south",
    "domain/original/area/wilderness/room_40_41", "east",
    "domain/original/area/wilderness/room_40_39", "west",
  });
}
