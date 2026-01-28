inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "north":"/chapter/prologue/area/ruined/room/entrance",
    "south":"/chapter/prologue/area/roadway/room44",
    "west":"/room/wilderness_room#X29",
    "east":"/room/wilderness_room#Z29",
  ]);

  set_light(1);
}
