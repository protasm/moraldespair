inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/roadway/room37",
    "north":"/chapter/prologue/area/roadway/room39",
    "west":"/room/wilderness_room#X19",
    "east":"/room/wilderness_room#Z19",
  ]);

  set_light(1);
}
