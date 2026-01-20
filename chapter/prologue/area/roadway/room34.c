inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room33", "south",
    "chapter/prologue/area/roadway/room35", "north",
    "room/wilderness_room#X23", "west",
    "room/wilderness_room#Z23", "east",
  });

  set_light(1);
}
