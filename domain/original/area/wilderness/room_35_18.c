inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_34_18", "north",
    "domain/original/area/wilderness/room_36_18", "south",
    "domain/original/area/wilderness/room_35_19", "east",
    "domain/original/area/wilderness/room_35_17", "west",
  });
}
