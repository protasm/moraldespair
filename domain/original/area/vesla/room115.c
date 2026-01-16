inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Ruined Gate";
  long_desc = "A broken stone arch leans over the road, its timbers split and sagging.\n"
              + "Crumbled masonry seals the passage, and old iron fittings lie rusted in the\n"
              + "weeds.\n";
  dest_dir = ({
    "domain/original/area/vesla/room116", "west",
    "domain/original/area/roadway/room14", "exit",
  });

  add_exit_alias("x", "exit");
}

void init() {
  ::init();

  //add_action("block_exit", "exit");
}

int block_exit() {
  write("The ruined gate has collapsed; the way to the wilderness is\n"
        + "impassable.\n");

  return 1;
}
