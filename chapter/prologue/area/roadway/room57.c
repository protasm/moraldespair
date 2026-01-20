inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room56", "west",
    "chapter/prologue/area/roadway/room58", "east",
    "room/wilderness_room#AN27", "north",
    "room/wilderness_room#AN29", "south",
  });

  set_light(1);
}
