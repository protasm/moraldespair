inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room4", "west",
    "chapter/prologue/area/roadway/room6", "east",
    "room/wilderness_room#P27", "north",
    "room/wilderness_room#P29", "south",
  });

  set_light(1);
}
