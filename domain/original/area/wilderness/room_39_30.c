inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_38_30", "north",
    "domain/original/area/wilderness/room_40_30", "south",
    "domain/original/area/wilderness/room_39_31", "east",
    "domain/original/area/wilderness/room_39_29", "west",
  });
}
