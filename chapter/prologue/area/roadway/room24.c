inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room23", "west",
    "chapter/prologue/area/roadway/room25", "east",
    "room/wilderness_room#AH27", "north",
    "room/wilderness_room#AH29", "south",
  });

  set_light(1);
}
