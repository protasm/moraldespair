inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/roadway/room35",
    "north":"/chapter/prologue/area/roadway/room37",
    "west":"/room/wilderness_room#X21",
    "east":"/room/wilderness_room#Z21",
  ]);

  set_light(1);
}
