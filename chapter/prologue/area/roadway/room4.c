inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room3", "west",
    "chapter/prologue/area/roadway/room5", "east",
    "room/wilderness_room#O27", "north",
    "room/wilderness_room#O29", "south",
  });

  set_light(1);
}
