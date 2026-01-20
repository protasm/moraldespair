inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Fallen Vault";
  long_desc = "A heavy door hangs askew on broken hinges, opening into a chamber choked with rubble. Iron bands are rusted through, and the floor has sunk into a shallow pit.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room225", "west",
    "chapter/prologue/area/ruined/room223", "east",
    "chapter/prologue/area/ruined/room121", "north",
  });
}
