inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_36_45", "north",
    "domain/original/area/wilderness/room_38_45", "south",
    "domain/original/area/wilderness/room_37_46", "east",
    "domain/original/area/wilderness/room_37_44", "west",
  });
}
