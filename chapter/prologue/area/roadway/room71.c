inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "north":"/chapter/prologue/area/roadway/room70",
    "south":"/chapter/prologue/area/dead/entrance",
    "west":"/room/wilderness_room#X44",
    "east":"/room/wilderness_room#Z44",
  ]);

  set_light(1);
}
