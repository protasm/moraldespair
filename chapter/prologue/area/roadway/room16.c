inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/ruined/entrance", "west",
    "chapter/prologue/area/roadway/room17", "east",
    "room/wilderness_room#Z27", "north",
    "room/wilderness_room#Z29", "south",
  });

  set_light(1);
}
