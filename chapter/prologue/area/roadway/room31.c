inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room30", "south",
    "chapter/prologue/area/roadway/room32", "north",
    "room/wilderness_room#X26", "west",
    "room/wilderness_room#Z26", "east",
  });

  set_light(1);
}
