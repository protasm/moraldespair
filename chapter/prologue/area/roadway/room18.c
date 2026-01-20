inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room17", "west",
    "chapter/prologue/area/roadway/room19", "east",
    "room/wilderness_room#AB27", "north",
    "room/wilderness_room#AB29", "south",
  });

  set_light(1);
}
