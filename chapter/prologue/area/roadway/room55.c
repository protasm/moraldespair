inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "north":"/chapter/prologue/area/roadway/room54",
    "south":"/chapter/prologue/area/roadway/room69",
    "west":"/room/wilderness_room#X41",
    "east":"/room/wilderness_room#Z41",
  ]);

  set_light(1);
}
