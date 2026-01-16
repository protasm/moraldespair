inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_26_20", "north",
    "domain/original/area/wilderness/room_28_20", "south",
    "domain/original/area/wilderness/room_27_21", "east",
    "domain/original/area/wilderness/room_27_19", "west",
  });
}
