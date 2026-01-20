inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room27", "west",
    "chapter/prologue/area/roadway/room56", "east",
    "room/wilderness_room#AL27", "north",
    "room/wilderness_room#AL29", "south",
  });

  set_light(1);
}
