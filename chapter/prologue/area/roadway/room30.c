inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/ruined/entrance", "south",
    "chapter/prologue/area/roadway/room31", "north",
    "room/wilderness_room#X27", "west",
    "room/wilderness_room#Z27", "east",
  });

  set_light(1);
}
