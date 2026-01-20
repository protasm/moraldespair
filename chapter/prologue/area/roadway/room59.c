inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room58", "west",
    "chapter/prologue/area/roadway/room60", "east",
    "room/wilderness_room#AP27", "north",
    "room/wilderness_room#AP29", "south",
  });

  set_light(1);
}
