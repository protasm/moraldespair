inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room21", "west",
    "chapter/prologue/area/roadway/room23", "east",
    "room/wilderness_room#AF27", "north",
    "room/wilderness_room#AF29", "south",
  });

  set_light(1);
}
