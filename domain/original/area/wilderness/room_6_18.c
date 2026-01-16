inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_5_18", "north",
    "domain/original/area/wilderness/room_7_18", "south",
    "domain/original/area/wilderness/room_6_19", "east",
    "domain/original/area/wilderness/room_6_17", "west",
  });
}
