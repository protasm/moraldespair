inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/roadway/room56",
    "east":"/chapter/prologue/area/roadway/room58",
    "north":"/room/wilderness_room#AN27",
    "south":"/room/wilderness_room#AN29",
  ]);

  set_light(1);
}
