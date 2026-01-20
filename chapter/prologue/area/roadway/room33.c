inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room32", "south",
    "chapter/prologue/area/roadway/room34", "north",
    "room/wilderness_room#X24", "west",
    "room/wilderness_room#Z24", "east",
  });

  set_light(1);
}
