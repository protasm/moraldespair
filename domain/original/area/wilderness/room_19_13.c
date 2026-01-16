inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_18_13", "north",
    "domain/original/area/wilderness/room_20_13", "south",
    "domain/original/area/wilderness/room_19_14", "east",
    "domain/original/area/wilderness/room_19_12", "west",
  });
}
