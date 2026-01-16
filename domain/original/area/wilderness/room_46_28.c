inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_45_28", "north",
    "domain/original/area/wilderness/room_47_28", "south",
    "domain/original/area/wilderness/room_46_29", "east",
    "domain/original/area/wilderness/room_46_27", "west",
  });
}
