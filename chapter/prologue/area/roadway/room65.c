inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/roadway/room64",
    "north":"/chapter/prologue/area/roadway/room66",
    "west":"/room/wilderness_room#X11",
    "east":"/room/wilderness_room#Z11",
  ]);

  set_light(1);
}
