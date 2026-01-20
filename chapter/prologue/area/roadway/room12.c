inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/roadway/room11",
    "east":"/chapter/prologue/area/roadway/room13",
    "north":"/room/wilderness_room#W27",
    "south":"/room/wilderness_room#W29",
  ]);

  set_light(1);
}
