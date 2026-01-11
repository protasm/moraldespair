inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Fallen Vault";
  long_desc = "A heavy door hangs askew on broken hinges, opening into a chamber choked with\n"
              + "rubble. Iron bands are rusted through, and the floor has sunk into a shallow\n"
              + "pit.\n";
  dest_dir = ({
    "domain/original/area/vesla/room225", "west",
    "domain/original/area/vesla/room223", "east",
    "domain/original/area/vesla/room121", "north",
  });
}
