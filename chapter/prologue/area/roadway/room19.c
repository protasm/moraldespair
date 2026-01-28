inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/roadway/room18",
    "east":"/chapter/prologue/area/roadway/room20",
    "north":"/room/wilderness_room#AC27",
    "south":"/room/wilderness_room#AC29",
  ]);

  set_light(1);
}
