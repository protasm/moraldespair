inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "north":"/chapter/prologue/area/roadway/room44",
    "south":"/chapter/prologue/area/roadway/room46",
    "west":"/room/wilderness_room#X31",
    "east":"/room/wilderness_room#Z31",
  ]);

  set_light(1);
}
