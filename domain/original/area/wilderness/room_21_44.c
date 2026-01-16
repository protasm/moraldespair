inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_20_44", "north",
    "domain/original/area/wilderness/room_22_44", "south",
    "domain/original/area/wilderness/room_21_45", "east",
    "domain/original/area/wilderness/room_21_43", "west",
  });
}
