inherit "room/room";

void create() {
  ::create();

    short_desc = "East River Track";
    long_desc = "Silt lies in shallow drifts along the edge of the road. A fallen shutter leans against the stone, water-dark and warped.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room205", "west",
        "chapter/prologue/area/ruined/room207", "east",
        "chapter/prologue/area/ruined/room397", "north",
    });

  set_light(1);
}
