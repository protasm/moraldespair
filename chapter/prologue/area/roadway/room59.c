inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/roadway/room58",
    "east":"/chapter/prologue/area/roadway/room60",
    "north":"/room/wilderness_room#AP27",
    "south":"/room/wilderness_room#AP29",
  ]);

  set_light(1);
}
