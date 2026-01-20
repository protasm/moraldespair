inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room2", "west",
    "chapter/prologue/area/roadway/room4", "east",
    "room/wilderness_room#N27", "north",
    "room/wilderness_room#N29", "south",
  });

  set_light(1);
}
