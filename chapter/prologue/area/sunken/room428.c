inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Drifted Platform";
  long_desc = "Scattered piers suggest a once-long span, now broken into bays. Wind has piled sand against one side, leaving the other scoured bare.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room97", "south",
    "chapter/prologue/area/sunken/room977", "west",
  });

  set_light(1);
}

void init() {
  ::init();

  //add_action("block_exit", "west");
}

int block_exit() {
  write("The way is blocked by a wall of broken stone.\n");
  return 1;
}
