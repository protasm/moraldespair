inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "north":"/chapter/prologue/area/roadway/room53",
    "south":"/chapter/prologue/area/roadway/room55",
    "west":"/room/wilderness_room#X40",
    "east":"/room/wilderness_room#Z40",
  ]);

  set_light(1);
}
