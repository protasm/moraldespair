inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room20", "west",
    "chapter/prologue/area/roadway/room22", "east",
    "room/wilderness_room#AE27", "north",
    "room/wilderness_room#AE29", "south",
  });

  set_light(1);
}
