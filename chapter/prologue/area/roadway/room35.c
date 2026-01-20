inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room34", "south",
    "chapter/prologue/area/roadway/room36", "north",
    "room/wilderness_room#X22", "west",
    "room/wilderness_room#Z22", "east",
  });

  set_light(1);
}
