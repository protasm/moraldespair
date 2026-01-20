inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room69", "north",
    "chapter/prologue/area/roadway/room71", "south",
    "room/wilderness_room#X43", "west",
    "room/wilderness_room#Z43", "east",
  });

  set_light(1);
}
