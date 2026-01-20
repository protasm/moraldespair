inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room38", "south",
    "chapter/prologue/area/roadway/room40", "north",
    "room/wilderness_room#X18", "west",
    "room/wilderness_room#Z18", "east",
  });

  set_light(1);
}
