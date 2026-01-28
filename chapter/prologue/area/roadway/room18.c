inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/roadway/room17",
    "east":"/chapter/prologue/area/roadway/room19",
    "north":"/room/wilderness_room#AB27",
    "south":"/room/wilderness_room#AB29",
  ]);

  set_light(1);
}
