inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_18_38", "north",
    "domain/original/area/wilderness/room_20_38", "south",
    "domain/original/area/wilderness/room_19_39", "east",
    "domain/original/area/wilderness/room_19_37", "west",
  });
}
