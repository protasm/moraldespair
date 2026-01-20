inherit "room/room";

void create() {
  ::create();

    short_desc = "East River Track";
    long_desc = "A shallow rut marks the center line, worn deep before the silence. Small piles of gravel gather against the curb.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room208", "west",
        "chapter/prologue/area/ruined/room210", "east",
        "chapter/prologue/area/ruined/room395", "north",
    });

  set_light(1);
}
