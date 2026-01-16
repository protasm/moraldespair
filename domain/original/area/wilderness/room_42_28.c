inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_41_28", "north",
    "domain/original/area/wilderness/room_43_28", "south",
    "domain/original/area/wilderness/room_42_29", "east",
    "domain/original/area/wilderness/room_42_27", "west",
  });
}
