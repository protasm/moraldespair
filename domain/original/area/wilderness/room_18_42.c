inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_17_42", "north",
    "domain/original/area/wilderness/room_19_42", "south",
    "domain/original/area/wilderness/room_18_43", "east",
    "domain/original/area/wilderness/room_18_41", "west",
  });
}
