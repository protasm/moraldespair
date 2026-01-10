inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Collapsed Vault";
  long_desc = "A heavy doorway hangs open on broken hinges, leading to a\n"
              + "chamber choked with debris. Iron bands are rusted through,\n"
              + "and the floor has buckled into a shallow pit.\n";
  dest_dir = ({
    "domain/original/area/vesla/room225", "west",
    "domain/original/area/vesla/room223", "east",
    "domain/original/area/vesla/room121", "north",
  });
}
