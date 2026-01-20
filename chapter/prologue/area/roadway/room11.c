inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room10", "west",
    "chapter/prologue/area/roadway/room12", "east",
    "room/wilderness_room#V27", "north",
    "room/wilderness_room#V29", "south",
  });

  set_light(1);
}
