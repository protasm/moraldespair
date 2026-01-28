inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "City of the Dead";
  long_desc = "A city overtaken by the dead.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/roadway/room71",
    "west" : "/room/wilderness_room#X45",
    "east" : "/room/wilderness_room#Z45",
    "south" : "/room/wilderness_room#Y46",
    "city" : "/chapter/prologue/area/dead/room1401",
  ]);

  add_exit_alias("c", "city");

  set_light(1);
}
