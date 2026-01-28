inherit "/room/room";

void create() {
  ::create();

  short_desc = "Faded Corridor";
  long_desc = "A shallow slope of debris leads down into a widened passage. Fire-blackened patches run along the base of the walls.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room107", "north",
    "chapter/prologue/area/sunken/room99", "south",
    "chapter/prologue/area/sunken/room1000", "east",
    "chapter/prologue/area/sunken/room97", "west",
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
