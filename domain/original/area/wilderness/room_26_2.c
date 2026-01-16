inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_25_2", "north",
    "domain/original/area/wilderness/room_27_2", "south",
    "domain/original/area/wilderness/room_26_3", "east",
    "domain/original/area/wilderness/room_26_1", "west",
  });
}
