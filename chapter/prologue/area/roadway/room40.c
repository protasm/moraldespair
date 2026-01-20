inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room39", "south",
    "chapter/prologue/area/roadway/room41", "north",
    "room/wilderness_room#X17", "west",
    "room/wilderness_room#Z17", "east",
  });

  set_light(1);
}
