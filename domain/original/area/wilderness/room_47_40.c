inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_46_40", "north",
    "domain/original/area/wilderness/room_48_40", "south",
    "domain/original/area/wilderness/room_47_41", "east",
    "domain/original/area/wilderness/room_47_39", "west",
  });
}
