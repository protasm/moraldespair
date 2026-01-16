inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_42_35", "north",
    "domain/original/area/wilderness/room_44_35", "south",
    "domain/original/area/wilderness/room_43_36", "east",
    "domain/original/area/wilderness/room_43_34", "west",
  });
}
