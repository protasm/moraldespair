inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_44_4", "north",
    "domain/original/area/wilderness/room_46_4", "south",
    "domain/original/area/wilderness/room_45_5", "east",
    "domain/original/area/wilderness/room_45_3", "west",
  });
}
