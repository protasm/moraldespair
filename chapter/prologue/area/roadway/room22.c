inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/roadway/room21",
    "east":"/chapter/prologue/area/roadway/room23",
    "north":"/room/wilderness_room#AF27",
    "south":"/room/wilderness_room#AF29",
  ]);

  set_light(1);
}
