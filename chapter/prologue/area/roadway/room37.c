inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/roadway/room36",
    "north":"/chapter/prologue/area/roadway/room38",
    "west":"/room/wilderness_room#X20",
    "east":"/room/wilderness_room#Z20",
  ]);

  set_light(1);
}
