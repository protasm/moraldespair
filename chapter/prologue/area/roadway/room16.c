inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/ruined/entrance",
    "east":"/chapter/prologue/area/roadway/room17",
    "north":"/room/wilderness_room#Z27",
    "south":"/room/wilderness_room#Z29",
  ]);

  set_light(1);
}
