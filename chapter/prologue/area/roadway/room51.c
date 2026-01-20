inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "north":"/chapter/prologue/area/roadway/room50",
    "south":"/chapter/prologue/area/roadway/room52",
    "west":"/room/wilderness_room#X37",
    "east":"/room/wilderness_room#Z37",
  ]);

  set_light(1);
}
