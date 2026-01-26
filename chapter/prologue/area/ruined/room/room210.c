inherit "/chapter/prologue/std/room";

void create() {
  ::create();

    short_desc = "East River Track";
    long_desc = "Cracked stones and broken mortar leave the roadway ragged. A rusted chain lies half sunk in the silt.";
    dest_dir = ([
      "west":"/chapter/prologue/area/ruined/room/room209",
      "east":"/chapter/prologue/area/ruined/room/room211",
      "north":"/chapter/prologue/area/ruined/room/room394",
    ]);

}
