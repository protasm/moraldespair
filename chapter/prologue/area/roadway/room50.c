inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room49", "north",
    "chapter/prologue/area/roadway/room51", "south",
    "room/wilderness_room#X36", "west",
    "room/wilderness_room#Z36", "east",
  });

  set_light(1);
}
