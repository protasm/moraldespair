inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_17_25", "north",
    "domain/original/area/wilderness/room_19_25", "south",
    "domain/original/area/wilderness/room_18_26", "east",
    "domain/original/area/wilderness/room_18_24", "west",
  });
}
