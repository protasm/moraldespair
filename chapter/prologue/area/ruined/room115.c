inherit "room/room";

void create() {
  ::create();

  short_desc = "Ruined Gate";
  long_desc = "A broken stone arch leans over the road, its timbers split and sagging. Crumbled masonry seals the passage, and old iron fittings lie rusted in the weeds.";
  dest_dir = ([
    "west":"/chapter/prologue/area/ruined/room116",
    "exit":"/chapter/prologue/area/ruined/entrance",
  ]);

  set_light(1);
  add_exit_alias("x", "exit");
}

void init() {
  ::init();

  //add_action("block_exit", "exit");
}

int block_exit() {
  write("The ruined gate has collapsed; the way to the wilderness is impassable.\n");

  return 1;
}
