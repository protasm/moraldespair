inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_43_41", "north",
    "domain/original/area/wilderness/room_45_41", "south",
    "domain/original/area/wilderness/room_44_42", "east",
    "domain/original/area/wilderness/room_44_40", "west",
  });
}
