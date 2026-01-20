inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room47", "north",
    "chapter/prologue/area/roadway/room49", "south",
    "room/wilderness_room#X34", "west",
    "room/wilderness_room#Z34", "east",
  });

  set_light(1);
}
