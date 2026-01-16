inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_38_18", "north",
    "domain/original/area/wilderness/room_40_18", "south",
    "domain/original/area/wilderness/room_39_19", "east",
    "domain/original/area/wilderness/room_39_17", "west",
  });
}
