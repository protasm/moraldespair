inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room64", "south",
    "chapter/prologue/area/roadway/room66", "north",
    "room/wilderness_room#X11", "west",
    "room/wilderness_room#Z11", "east",
  });

  set_light(1);
}
