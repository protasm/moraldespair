inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_27_36", "north",
    "domain/original/area/wilderness/room_29_36", "south",
    "domain/original/area/wilderness/room_28_37", "east",
    "domain/original/area/wilderness/room_28_35", "west",
  });
}
