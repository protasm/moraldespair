inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Colorless Wilderness";
  long_desc = "Colorless Wilderness\n";

  dest_dir = ({
    "domain/original/area/wilderness/room_17_43", "north",
    "domain/original/area/wilderness/room_19_43", "south",
    "domain/original/area/wilderness/room_18_44", "east",
    "domain/original/area/wilderness/room_18_42", "west",
  });
}
