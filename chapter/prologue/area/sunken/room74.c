inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Scarred Hollow";
  long_desc = "The route skirts a collapsed chamber, its edge cut clean by fire. Hollow window frames stare out, their ledges buried in dust.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room1018", "north",
    "chapter/prologue/area/sunken/room1019", "south",
    "chapter/prologue/area/sunken/room73", "east",
    "chapter/prologue/area/sunken/room75", "west",
  });

  set_light(1);
}

void init() {
  ::init();

  //add_action("block_exit", "north");
}

int block_exit() {
  write("The way is blocked by a wall of broken stone.\n");
  return 1;
}
