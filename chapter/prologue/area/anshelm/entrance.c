inherit "room/room";

void create() {
  ::create();

  short_desc = "Defiled City";
  long_desc = "The defiled remains of a final refuge.";
  dest_dir = ({
    "chapter/prologue/area/roadway/room68", "south",
    "room/wilderness_room#Y6", "north",
    "room/wilderness_room#X7", "west",
    "room/wilderness_room#Z7", "east",
    "chapter/prologue/area/anshelm/room235", "city",
  });

  add_exit_alias("c", "city");

  set_light(1);
}
