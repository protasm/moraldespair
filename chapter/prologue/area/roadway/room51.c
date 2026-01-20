inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room50", "north",
    "chapter/prologue/area/roadway/room52", "south",
    "room/wilderness_room#X37", "west",
    "room/wilderness_room#Z37", "east",
  });

  set_light(1);
}
