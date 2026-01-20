inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room67", "south",
    "chapter/prologue/area/anshelm/entrance", "north",
    "room/wilderness_room#X8", "west",
    "room/wilderness_room#Z8", "east",
  });

  set_light(1);
}
