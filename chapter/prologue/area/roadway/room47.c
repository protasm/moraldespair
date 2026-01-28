inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "north":"/chapter/prologue/area/roadway/room46",
    "south":"/chapter/prologue/area/roadway/room48",
    "west":"/room/wilderness_room#X33",
    "east":"/room/wilderness_room#Z33",
  ]);

  set_light(1);
}
