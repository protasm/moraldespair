inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/roadway/room59",
    "east":"/chapter/prologue/area/roadway/room61",
    "north":"/room/wilderness_room#AQ27",
    "south":"/room/wilderness_room#AQ29",
  ]);

  set_light(1);
}
