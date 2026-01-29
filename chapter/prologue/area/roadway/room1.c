inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/sunken/entrance",
    "east":"/chapter/prologue/area/roadway/room2",
    "north":"/chapter/prologue/std/wilderness_room#L27",
    "south":"/chapter/prologue/std/wilderness_room#L29",
  ]);

  set_light(1);
}
