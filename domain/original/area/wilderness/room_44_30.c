inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_43_30", "north",
    "domain/original/area/wilderness/room_45_30", "south",
    "domain/original/area/wilderness/room_44_31", "east",
    "domain/original/area/wilderness/room_44_29", "west",
  });
}
