inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_44_36", "north",
    "domain/original/area/wilderness/room_46_36", "south",
    "domain/original/area/wilderness/room_45_37", "east",
    "domain/original/area/wilderness/room_45_35", "west",
  });
}
