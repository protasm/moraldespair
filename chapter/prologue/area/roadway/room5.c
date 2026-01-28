inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/roadway/room4",
    "east":"/chapter/prologue/area/roadway/room6",
    "north":"/room/wilderness_room#P27",
    "south":"/room/wilderness_room#P29",
  ]);

  set_light(1);
}
