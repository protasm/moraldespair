inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_38_42", "north",
    "domain/original/area/wilderness/room_40_42", "south",
    "domain/original/area/wilderness/room_39_43", "east",
    "domain/original/area/wilderness/room_39_41", "west",
  });
}
