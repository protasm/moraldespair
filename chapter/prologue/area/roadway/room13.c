inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room12", "west",
    "chapter/prologue/area/ruined/entrance", "east",
    "room/wilderness_room#X27", "north",
    "room/wilderness_room#X29", "south",
  });
}
