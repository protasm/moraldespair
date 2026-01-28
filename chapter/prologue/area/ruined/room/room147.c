inherit "/chapter/prologue/std/room";

void create() {
  ::create();

    short_desc = "West River Track";
    long_desc = "The river road bends past a slumped doorway, its threshold choked with debris. Pale lichen maps the stone, and no tracks disturb the dust.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room/room846",
      "west":"/chapter/prologue/area/ruined/room/room146",
      "east":"/chapter/prologue/area/ruined/room/room148",
      "north":"/chapter/prologue/area/ruined/room/room841",
    ]);

}
