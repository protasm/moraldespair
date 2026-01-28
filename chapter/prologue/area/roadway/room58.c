inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/roadway/room57",
    "east":"/chapter/prologue/area/roadway/room59",
    "north":"/room/wilderness_room#AO27",
    "south":"/room/wilderness_room#AO29",
  ]);

  set_light(1);
}
