inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_29_37", "north",
    "domain/original/area/wilderness/room_31_37", "south",
    "domain/original/area/wilderness/room_30_38", "east",
    "domain/original/area/wilderness/room_30_36", "west",
  });
}
