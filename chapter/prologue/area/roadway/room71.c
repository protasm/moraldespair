inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room70", "north",
    "domain/original/area/indel/entrance", "south",
    "room/wilderness_room#X44", "west",
    "room/wilderness_room#Z44", "east",
  });

  set_light(1);
}
