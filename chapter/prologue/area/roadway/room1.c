inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/sunken/entrance",
    "east":"/chapter/prologue/area/roadway/room2",
    "north":"/room/wilderness_room#L27",
    "south":"/room/wilderness_room#L29",
  ]);

  set_light(1);
}
