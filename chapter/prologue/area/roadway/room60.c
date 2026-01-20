inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room59", "west",
    "chapter/prologue/area/roadway/room61", "east",
    "room/wilderness_room#AQ27", "north",
    "room/wilderness_room#AQ29", "south",
  });

  set_light(1);
}
