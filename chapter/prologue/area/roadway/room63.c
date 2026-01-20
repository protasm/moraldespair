inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room62", "south",
    "chapter/prologue/area/roadway/room64", "north",
    "room/wilderness_room#X13", "west",
    "room/wilderness_room#Z13", "east",
  });

  set_light(1);
}
