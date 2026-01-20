inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room31", "south",
    "chapter/prologue/area/roadway/room33", "north",
    "room/wilderness_room#X25", "west",
    "room/wilderness_room#Z25", "east",
  });

  set_light(1);
}
