inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_16_42", "north",
    "domain/original/area/wilderness/room_18_42", "south",
    "domain/original/area/wilderness/room_17_43", "east",
    "domain/original/area/wilderness/room_17_41", "west",
  });
}
