inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_37_32", "north",
    "domain/original/area/wilderness/room_39_32", "south",
    "domain/original/area/wilderness/room_38_33", "east",
    "domain/original/area/wilderness/room_38_31", "west",
  });
}
