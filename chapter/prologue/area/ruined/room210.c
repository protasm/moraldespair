inherit "room/room";

void create() {
  ::create();

    short_desc = "East River Track";
    long_desc = "Cracked stones and broken mortar leave the roadway ragged. A rusted chain lies half sunk in the silt.";
    dest_dir = ([
      "west":"/chapter/prologue/area/ruined/room209",
      "east":"/chapter/prologue/area/ruined/room211",
      "north":"/chapter/prologue/area/ruined/room394",
    ]);

  set_light(1);
}
