inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ([
    "north":"/chapter/prologue/area/roadway/room69",
    "south":"/chapter/prologue/area/roadway/room71",
    "west":"/room/wilderness_room#X43",
    "east":"/room/wilderness_room#Z43",
  ]);

  set_light(1);
}
