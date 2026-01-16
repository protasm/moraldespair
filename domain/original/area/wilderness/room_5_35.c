inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_4_35", "north",
    "domain/original/area/wilderness/room_6_35", "south",
    "domain/original/area/wilderness/room_5_36", "east",
    "domain/original/area/wilderness/room_5_34", "west",
  });
}
