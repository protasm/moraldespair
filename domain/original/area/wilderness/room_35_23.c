inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_34_23", "north",
    "domain/original/area/wilderness/room_36_23", "south",
    "domain/original/area/wilderness/room_35_24", "east",
    "domain/original/area/wilderness/room_35_22", "west",
  });
}
