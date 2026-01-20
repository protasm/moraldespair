inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room51", "north",
    "chapter/prologue/area/roadway/room53", "south",
    "room/wilderness_room#X38", "west",
    "room/wilderness_room#Z38", "east",
  });

  set_light(1);
}
