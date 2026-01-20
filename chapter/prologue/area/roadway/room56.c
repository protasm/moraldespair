inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room28", "west",
    "chapter/prologue/area/roadway/room57", "east",
    "room/wilderness_room#AM27", "north",
    "room/wilderness_room#AM29", "south",
  });

  set_light(1);
}
