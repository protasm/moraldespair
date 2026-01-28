inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/roadway/room33",
    "north":"/chapter/prologue/area/roadway/room35",
    "west":"/room/wilderness_room#X23",
    "east":"/room/wilderness_room#Z23",
  ]);

  set_light(1);
}
