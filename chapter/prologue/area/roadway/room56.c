inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/roadway/room28",
    "east":"/chapter/prologue/area/roadway/room57",
    "north":"/room/wilderness_room#AM27",
    "south":"/room/wilderness_room#AM29",
  ]);

  set_light(1);
}
