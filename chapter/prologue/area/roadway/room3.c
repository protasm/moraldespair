inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/roadway/room2",
    "east":"/chapter/prologue/area/roadway/room4",
    "north":"/room/wilderness_room#N27",
    "south":"/room/wilderness_room#N29",
  ]);

  set_light(1);
}
