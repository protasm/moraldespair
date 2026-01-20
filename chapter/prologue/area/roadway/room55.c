inherit "room/room";

void create() {
  ::create();

  short_desc = "Walking on a roadway";
  long_desc = "Walking on a roadway.\n";
  dest_dir = ({
    "chapter/prologue/area/roadway/room54", "north",
    "chapter/prologue/area/roadway/room69", "south",
    "room/wilderness_room#X41", "west",
    "room/wilderness_room#Z41", "east",
  });

  set_light(1);
}
