inherit "room/room";

void create() {
  ::create();

  short_desc = "Western Gate";
  long_desc = "The western gate has collapsed into a heap of stone and splintered wood. Rusted fittings lie half buried, and the blocked passage holds a deep, unmoving quiet.";
  dest_dir = ([
    "east":"/chapter/prologue/area/ruined/room133",
    "exit":"/chapter/prologue/area/roadway/room12",
  ]);

  add_exit_alias("x", "exit");

  set_light(1);
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
