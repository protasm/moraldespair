inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_25_33", "north",
    "domain/original/area/wilderness/room_27_33", "south",
    "domain/original/area/wilderness/room_26_34", "east",
    "domain/original/area/wilderness/room_26_32", "west",
  });
}
