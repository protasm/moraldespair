inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/roadway/room20",
    "east":"/chapter/prologue/area/roadway/room22",
    "north":"/room/wilderness_room#AE27",
    "south":"/room/wilderness_room#AE29",
  ]);

  set_light(1);
}
