inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room48", "north",
    "chapter/prologue/area/roadway/room50", "south",
    "room/wilderness_room#X35", "west",
    "room/wilderness_room#Z35", "east",
  });

  set_light(1);
}
