inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Cracked Drop";
  long_desc = "The space broadens into a shallow, rubble-filled bowl where paths meet. Rust-red streaks mark where metal once lay, now long gone.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room57", "east",
    "chapter/prologue/area/sunken/room1027", "west",
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
