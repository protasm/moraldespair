inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/roadway/room30",
    "north":"/chapter/prologue/area/roadway/room32",
    "west":"/room/wilderness_room#X26",
    "east":"/room/wilderness_room#Z26",
  ]);

  set_light(1);
}
