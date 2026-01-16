inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_42_6", "north",
    "domain/original/area/wilderness/room_44_6", "south",
    "domain/original/area/wilderness/room_43_7", "east",
    "domain/original/area/wilderness/room_43_5", "west",
  });
}
