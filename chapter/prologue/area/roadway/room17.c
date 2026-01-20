inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room16", "west",
    "chapter/prologue/area/roadway/room18", "east",
    "room/wilderness_room#AA27", "north",
    "room/wilderness_room#AA29", "south",
  });

  set_light(1);
}
