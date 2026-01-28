inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/roadway/room42",
    "north":"/chapter/prologue/area/roadway/room63",
    "west":"/room/wilderness_room#X14",
    "east":"/room/wilderness_room#Z14",
  ]);

  set_light(1);
}
