inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_39_44", "north",
    "domain/original/area/wilderness/room_41_44", "south",
    "domain/original/area/wilderness/room_40_45", "east",
    "domain/original/area/wilderness/room_40_43", "west",
  });
}
