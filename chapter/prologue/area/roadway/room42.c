inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room41", "south",
    "chapter/prologue/area/roadway/room62", "north",
    "room/wilderness_room#X15", "west",
    "room/wilderness_room#Z15", "east",
  });
}
