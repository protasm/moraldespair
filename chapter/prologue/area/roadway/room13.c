inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/roadway/room12",
    "east":"/chapter/prologue/area/ruined/entrance",
    "north":"/room/wilderness_room#X27",
    "south":"/room/wilderness_room#X29",
  ]);

  set_light(1);
}
