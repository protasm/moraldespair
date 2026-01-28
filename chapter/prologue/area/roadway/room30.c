inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room/entrance",
    "north":"/chapter/prologue/area/roadway/room31",
    "west":"/room/wilderness_room#X27",
    "east":"/room/wilderness_room#Z27",
  ]);

  set_light(1);
}
