inherit "room/room";

void create() {
  ::create();

    short_desc = "East River Track";
    long_desc = "Silt lies in shallow drifts along the edge of the road. A fallen shutter leans against the stone, water-dark and warped.";
    dest_dir = ([
      "west":"/chapter/prologue/area/ruined/room205",
      "east":"/chapter/prologue/area/ruined/room207",
      "north":"/chapter/prologue/area/ruined/room397",
    ]);

  set_light(1);
}
