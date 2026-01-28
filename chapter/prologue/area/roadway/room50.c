inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "north":"/chapter/prologue/area/roadway/room49",
    "south":"/chapter/prologue/area/roadway/room51",
    "west":"/room/wilderness_room#X36",
    "east":"/room/wilderness_room#Z36",
  ]);

  set_light(1);
}
