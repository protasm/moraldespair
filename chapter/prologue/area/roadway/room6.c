inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/roadway/room5",
    "east":"/chapter/prologue/area/roadway/room7",
    "north":"/room/wilderness_room#Q27",
    "south":"/room/wilderness_room#Q29",
  ]);

  set_light(1);
}
