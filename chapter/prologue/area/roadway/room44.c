inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "north":"/chapter/prologue/area/roadway/room43",
    "south":"/chapter/prologue/area/roadway/room45",
    "west":"/room/wilderness_room#X30",
    "east":"/room/wilderness_room#Z30",
  ]);

  set_light(1);
}
