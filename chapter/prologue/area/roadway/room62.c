inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room42", "south",
    "chapter/prologue/area/roadway/room63", "north",
    "room/wilderness_room#X14", "west",
    "room/wilderness_room#Z14", "east",
  });

  set_light(1);
}
