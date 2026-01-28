inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/roadway/room39",
    "north":"/chapter/prologue/area/roadway/room41",
    "west":"/room/wilderness_room#X17",
    "east":"/room/wilderness_room#Z17",
  ]);

  set_light(1);
}
