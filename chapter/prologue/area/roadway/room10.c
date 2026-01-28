inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/roadway/room9",
    "east":"/chapter/prologue/area/roadway/room11",
    "north":"/room/wilderness_room#U27",
    "south":"/room/wilderness_room#U29",
  ]);

  set_light(1);
}
