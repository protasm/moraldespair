inherit "room/room";

void create() {
  ::create();

  short_desc = "Fallen Vault";
  long_desc = "A heavy door hangs askew on broken hinges, opening into a chamber choked with rubble. Iron bands are rusted through, and the floor has sunk into a shallow pit.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room225", "west",
    "chapter/prologue/area/ruined/room223", "east",
    "chapter/prologue/area/ruined/room121", "north",
  });

  set_light(1);
}
