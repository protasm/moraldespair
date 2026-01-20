inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "north":"/chapter/prologue/area/roadway/room51",
    "south":"/chapter/prologue/area/roadway/room53",
    "west":"/room/wilderness_room#X38",
    "east":"/room/wilderness_room#Z38",
  ]);

  set_light(1);
}
