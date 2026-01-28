inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Defiled City";
  long_desc = "The defiled remains of a final refuge.";
  dest_dir = ([
    "south" : "/chapter/prologue/area/roadway/room68",
    "north" : "/room/wilderness_room#Y6",
    "west" : "/room/wilderness_room#X7",
    "east" : "/room/wilderness_room#Z7",
    "city" : "/chapter/prologue/area/refuge/room235",
  ]);

  add_exit_alias("c", "city");

  set_light(1);
}
