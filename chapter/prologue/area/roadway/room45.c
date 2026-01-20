inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room44", "north",
    "chapter/prologue/area/roadway/room46", "south",
    "room/wilderness_room#X31", "west",
    "room/wilderness_room#Z31", "east",
  });

  set_light(1);
}
