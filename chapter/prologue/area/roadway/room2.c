inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room1", "west",
    "chapter/prologue/area/roadway/room3", "east",
    "room/wilderness_room#M27", "north",
    "room/wilderness_room#M29", "south",
  });

  set_light(1);
}
