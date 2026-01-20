inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room35", "south",
    "chapter/prologue/area/roadway/room37", "north",
    "room/wilderness_room#X21", "west",
    "room/wilderness_room#Z21", "east",
  });

  set_light(1);
}
