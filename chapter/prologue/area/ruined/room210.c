inherit "room/room";

void create() {
  ::create();

    short_desc = "East River Track";
    long_desc = "Cracked stones and broken mortar leave the roadway ragged. A rusted chain lies half sunk in the silt.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room209", "west",
        "chapter/prologue/area/ruined/room211", "east",
        "chapter/prologue/area/ruined/room394", "north",
    });

  set_light(1);
}
