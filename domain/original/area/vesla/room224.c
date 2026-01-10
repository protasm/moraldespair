inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Fallen Vault";
  long_desc = "A heavy door hangs askew on broken hinges, opening into\n"
              + "a chamber choked with rubble.\n"
              + "Iron bands are rusted through, and the floor has sunk\n"
              + "into a shallow pit.\n";
  dest_dir = ({
    "domain/original/area/vesla/room225", "west",
    "domain/original/area/vesla/room223", "east",
    "domain/original/area/vesla/room121", "north",
  });
}
