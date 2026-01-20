inherit "room/room";

void create() {
  ::create();

    short_desc = "East River Track";
    long_desc = "A shallow rut marks the center line, worn deep before the silence. Small piles of gravel gather against the curb.";
    dest_dir = ([
      "west":"/chapter/prologue/area/ruined/room208",
      "east":"/chapter/prologue/area/ruined/room210",
      "north":"/chapter/prologue/area/ruined/room395",
    ]);

  set_light(1);
}
