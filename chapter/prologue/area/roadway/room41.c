inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/roadway/room40",
    "north":"/chapter/prologue/area/roadway/room42",
    "west":"/room/wilderness_room#X16",
    "east":"/room/wilderness_room#Z16",
  ]);

  set_light(1);
}
