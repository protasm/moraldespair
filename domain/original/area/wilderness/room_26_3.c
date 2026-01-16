inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_25_3", "north",
    "domain/original/area/wilderness/room_27_3", "south",
    "domain/original/area/wilderness/room_26_4", "east",
    "domain/original/area/wilderness/room_26_2", "west",
  });
}
