inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Fallen Vault";
  long_desc = "A heavy door hangs askew on broken hinges, opening into a chamber choked with rubble. Iron bands are rusted through, and the floor has sunk into a shallow pit.";
  dest_dir = ([
    "west":"/chapter/prologue/area/ruined/room/room225",
    "east":"/chapter/prologue/area/ruined/room/room223",
    "north":"/chapter/prologue/area/ruined/room/room121",
  ]);

}
