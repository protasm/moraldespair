inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Alley End";
  long_desc = "The alley narrows to a dead end cluttered with collapsed beams. Damp stains\nrun down the brick where rooflines failed.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room323",
    "north":"/chapter/prologue/area/silent/room325",
  ]);

  set_light(1);
}
