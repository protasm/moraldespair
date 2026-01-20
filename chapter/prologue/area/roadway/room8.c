inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/roadway/room7",
    "east":"/chapter/prologue/area/roadway/room9",
    "north":"/room/wilderness_room#S27",
    "south":"/room/wilderness_room#S29",
  ]);

  set_light(1);
}
