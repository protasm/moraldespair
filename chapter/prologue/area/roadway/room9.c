inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/roadway/room8",
    "east":"/chapter/prologue/area/roadway/room10",
    "north":"/room/wilderness_room#T27",
    "south":"/room/wilderness_room#T29",
  ]);

  set_light(1);
}
