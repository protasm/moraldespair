inherit "room/room";

void create() {
  ::create();

  short_desc = "Stone Doors";
  long_desc =
    "Two heavy doors hang ajar, their iron hinges rusted thick. A draft moves\n"
    "through the cracked threshold.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1330", "east",
    "domain/original/area/anshelm/room1328", "west",
  });

  set_light(1);
}
