inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room24", "west",
    "chapter/prologue/area/roadway/room26", "east",
    "room/wilderness_room#AI27", "north",
    "room/wilderness_room#AI29", "south",
  });

  set_light(1);
}
