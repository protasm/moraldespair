inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Western Gate";
  long_desc = "The western gate has collapsed into a heap of stone and\n"
              + "splintered wood. Rusted fittings lie half buried, and the\n"
              + "blocked passage holds a deep, unmoving quiet.\n";
  dest_dir = ({
    "domain/original/area/vesla/room133", "east",
    "domain/original/area/roadway/room29", "exit",
  });
}

void init() {
  ::init();
  add_action("block_exit", "exit");
}

int block_exit() {
  write("The ruined gate is choked with stone; the wilderness beyond is\n"
        + "impassable.\n");
  return 1;
}
