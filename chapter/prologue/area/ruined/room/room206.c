inherit "//chapter/prologue/std/room";

void create() {
  ::create();

    short_desc = "East River Track";
    long_desc = "Silt lies in shallow drifts along the edge of the road. A fallen shutter leans against the stone, water-dark and warped.";
    dest_dir = ([
      "west":"/chapter/prologue/area/ruined/room/room205",
      "east":"/chapter/prologue/area/ruined/room/room207",
      "north":"/chapter/prologue/area/ruined/room/room397",
    ]);

}
