inherit "room/room";

void create() {
  ::create();

  short_desc = "Barrack Road";
  long_desc =
    "Long stone halls march along the street, their roofs partly fallen. Rusted\n"
    "nails and timbers lie in heaps.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room267", "east",
    "chapter/prologue/area/anshelm/room269", "west",
  });

  set_light(1);
}
