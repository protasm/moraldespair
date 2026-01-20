inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/roadway/room60",
    "east":"/chapter/prologue/area/silent/entrance",
    "north":"/room/wilderness_room#AR27",
    "south":"/room/wilderness_room#AR29",
  ]);

  set_light(1);
}
