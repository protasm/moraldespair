inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/roadway/room19",
    "east":"/chapter/prologue/area/roadway/room21",
    "north":"/room/wilderness_room#AD27",
    "south":"/room/wilderness_room#AD29",
  ]);

  set_light(1);
}
