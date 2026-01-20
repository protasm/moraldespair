inherit "room/room";

void create() {
  ::create();

  short_desc = "Pale Manor";
  long_desc = "A pale manor stands behind a tangle of dead hedges. Its walls are stained and\nits windows are blind.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room380", "south",
  });

  set_light(1);
}
