inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_49_28", "north",
    "domain/original/area/wilderness/room_51_28", "south",
    "domain/original/area/wilderness/room_50_29", "east",
    "domain/original/area/wilderness/room_50_27", "west",
  });
}
