inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room40", "south",
    "chapter/prologue/area/roadway/room42", "north",
    "room/wilderness_room#X16", "west",
    "room/wilderness_room#Z16", "east",
  });

  set_light(1);
}
