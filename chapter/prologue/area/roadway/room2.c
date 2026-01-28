inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/roadway/room1",
    "east":"/chapter/prologue/area/roadway/room3",
    "north":"/room/wilderness_room#M27",
    "south":"/room/wilderness_room#M29",
  ]);

  set_light(1);
}
