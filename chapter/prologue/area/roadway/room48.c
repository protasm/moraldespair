inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "north":"/chapter/prologue/area/roadway/room47",
    "south":"/chapter/prologue/area/roadway/room49",
    "west":"/room/wilderness_room#X34",
    "east":"/room/wilderness_room#Z34",
  ]);

  set_light(1);
}
