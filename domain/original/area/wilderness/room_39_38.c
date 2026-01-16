inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_38_38", "north",
    "domain/original/area/wilderness/room_40_38", "south",
    "domain/original/area/wilderness/room_39_39", "east",
    "domain/original/area/wilderness/room_39_37", "west",
  });
}
