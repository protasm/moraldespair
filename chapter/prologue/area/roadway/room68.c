inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/roadway/room67",
    "north":"/chapter/prologue/area/refuge/entrance",
    "west":"/room/wilderness_room#X8",
    "east":"/room/wilderness_room#Z8",
  ]);

  set_light(1);
}
