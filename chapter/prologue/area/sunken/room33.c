inherit "room/room";

void create() {
  ::create();

  short_desc = "Broken Passage";
  long_desc = "A long strip of stonework drifts under dunes, only a spine still visible. Fire- blackened patches run along the base of the walls.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room32", "east",
    "chapter/prologue/area/sunken/room34", "west",
  });

  set_light(1);
}
