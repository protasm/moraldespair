inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/roadway/room41",
    "north":"/chapter/prologue/area/roadway/room62",
    "west":"/room/wilderness_room#X15",
    "east":"/room/wilderness_room#Z15",
  ]);

  set_light(1);
}
