inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_4_33", "north",
    "domain/original/area/wilderness/room_6_33", "south",
    "domain/original/area/wilderness/room_5_34", "east",
    "domain/original/area/wilderness/room_5_32", "west",
  });
}
