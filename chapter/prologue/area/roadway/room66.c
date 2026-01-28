inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/roadway/room65",
    "north":"/chapter/prologue/area/roadway/room67",
    "west":"/room/wilderness_room#X10",
    "east":"/room/wilderness_room#Z10",
  ]);

  set_light(1);
}
