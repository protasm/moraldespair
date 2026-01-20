inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room52", "north",
    "chapter/prologue/area/roadway/room54", "south",
    "room/wilderness_room#X39", "west",
    "room/wilderness_room#Z39", "east",
  });

  set_light(1);
}
