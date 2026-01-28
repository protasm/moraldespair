inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Wind-Scoured Reach";
  long_desc = "The way pinches tight, then opens again into scattered foundations. Ash and grit collect in corners, damped by occasional trickles.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room989", "east",
    "chapter/prologue/area/sunken/room58", "west",
  });

  set_light(1);
}

void init() {
  ::init();

  //add_action("block_exit", "east");
}

int block_exit() {
  write("The way is blocked by a wall of broken stone.\n");
  return 1;
}
