inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Pale Manor";
  long_desc = "A pale manor stands behind a tangle of dead hedges. Its walls are stained and\nits windows are blind.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room380",
  ]);

  set_light(1);
}
