inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/roadway/room34",
    "north":"/chapter/prologue/area/roadway/room36",
    "west":"/room/wilderness_room#X22",
    "east":"/room/wilderness_room#Z22",
  ]);

  set_light(1);
}
