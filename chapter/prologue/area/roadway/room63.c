inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/roadway/room62",
    "north":"/chapter/prologue/area/roadway/room64",
    "west":"/room/wilderness_room#X13",
    "east":"/room/wilderness_room#Z13",
  ]);

  set_light(1);
}
