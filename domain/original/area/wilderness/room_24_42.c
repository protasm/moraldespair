inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_23_42", "north",
    "domain/original/area/wilderness/room_25_42", "south",
    "domain/original/area/wilderness/room_24_43", "east",
    "domain/original/area/wilderness/room_24_41", "west",
  });
}
