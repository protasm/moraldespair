inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/ruined/room/entrance",
    "east":"/chapter/prologue/area/roadway/room17",
    "north":"/chapter/prologue/std/wilderness_room#Z27",
    "south":"/chapter/prologue/std/wilderness_room#Z29",
  ]);

  set_light(1);
}
