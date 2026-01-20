inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/ruined/entrance", "north",
    "chapter/prologue/area/roadway/room44", "south",
    "room/wilderness_room#X29", "west",
    "room/wilderness_room#Z29", "east",
  });

  set_light(1);
}
