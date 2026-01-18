inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Western Gate";
  long_desc = "The western gate has collapsed into a heap of stone and splintered wood. Rusted fittings lie half buried, and the blocked passage holds a deep, unmoving quiet.";
  dest_dir = ({
    "domain/original/area/vesla/room133", "east",
    "domain/original/area/roadway/room12", "exit",
  });

  add_exit_alias("x", "exit");
}

void init() {
  ::init();

  //add_action("block_exit", "exit");
}

int block_exit() {
  write("The ruined gate is choked with stone; the wilderness beyond is\n"
        + "impassable.\n");
  return 1;
}
