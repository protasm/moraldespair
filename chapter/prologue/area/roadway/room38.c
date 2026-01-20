inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room37", "south",
    "chapter/prologue/area/roadway/room39", "north",
    "room/wilderness_room#X19", "west",
    "room/wilderness_room#Z19", "east",
  });

  set_light(1);
}
