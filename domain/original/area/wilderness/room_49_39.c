inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_48_39", "north",
    "domain/original/area/wilderness/room_50_39", "south",
    "domain/original/area/wilderness/room_49_40", "east",
    "domain/original/area/wilderness/room_49_38", "west",
  });
}
