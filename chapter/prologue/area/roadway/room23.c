inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/roadway/room22",
    "east":"/chapter/prologue/area/roadway/room24",
    "north":"/room/wilderness_room#AG27",
    "south":"/room/wilderness_room#AG29",
  ]);

  set_light(1);
}
