inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room46", "north",
    "chapter/prologue/area/roadway/room48", "south",
    "room/wilderness_room#X33", "west",
    "room/wilderness_room#Z33", "east",
  });

  set_light(1);
}
