inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_29_35", "north",
    "domain/original/area/wilderness/room_31_35", "south",
    "domain/original/area/wilderness/room_30_36", "east",
    "domain/original/area/wilderness/room_30_34", "west",
  });
}
