inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/roadway/room23",
    "east":"/chapter/prologue/area/roadway/room25",
    "north":"/room/wilderness_room#AH27",
    "south":"/room/wilderness_room#AH29",
  ]);

  set_light(1);
}
