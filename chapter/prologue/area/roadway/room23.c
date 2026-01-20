inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room22", "west",
    "chapter/prologue/area/roadway/room24", "east",
    "room/wilderness_room#AG27", "north",
    "room/wilderness_room#AG29", "south",
  });

  set_light(1);
}
