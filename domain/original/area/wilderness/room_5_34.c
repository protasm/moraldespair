inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_4_34", "north",
    "domain/original/area/wilderness/room_6_34", "south",
    "domain/original/area/wilderness/room_5_35", "east",
    "domain/original/area/wilderness/room_5_33", "west",
  });
}
