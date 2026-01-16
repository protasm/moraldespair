inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_29_44", "north",
    "domain/original/area/wilderness/room_31_44", "south",
    "domain/original/area/wilderness/room_30_45", "east",
    "domain/original/area/wilderness/room_30_43", "west",
  });
}
