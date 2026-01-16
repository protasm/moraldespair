inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Stone Doors";
  long_desc =
    "Two heavy doors hang ajar, their iron hinges rusted thick. A draft moves\n"
    "through the cracked threshold.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1330", "east",
    "domain/original/area/anshelm/room1328", "west",
  });
}
