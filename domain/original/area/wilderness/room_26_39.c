inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_25_39", "north",
    "domain/original/area/wilderness/room_27_39", "south",
    "domain/original/area/wilderness/room_26_40", "east",
    "domain/original/area/wilderness/room_26_38", "west",
  });
}
