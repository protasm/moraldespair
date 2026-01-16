inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_19_37", "north",
    "domain/original/area/wilderness/room_21_37", "south",
    "domain/original/area/wilderness/room_20_38", "east",
    "domain/original/area/wilderness/room_20_36", "west",
  });
}
