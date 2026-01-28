inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "north":"/chapter/prologue/area/roadway/room52",
    "south":"/chapter/prologue/area/roadway/room54",
    "west":"/room/wilderness_room#X39",
    "east":"/room/wilderness_room#Z39",
  ]);

  set_light(1);
}
