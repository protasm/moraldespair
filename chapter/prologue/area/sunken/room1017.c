inherit "room/room";

void create() {
  ::create();

  short_desc = "Rubble-Strewn Walk";
  long_desc = "An open stretch of hard-packed grit marks a crossing of several lines. Splintered tiles crunch underfoot, mixed with crushed brick.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room73", "south",
    "chapter/prologue/area/sunken/room1018", "west",
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
