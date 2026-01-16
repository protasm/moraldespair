inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_29_45", "north",
    "domain/original/area/wilderness/room_31_45", "south",
    "domain/original/area/wilderness/room_30_46", "east",
    "domain/original/area/wilderness/room_30_44", "west",
  });
}
