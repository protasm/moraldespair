inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Pale Manor";
  long_desc = "A pale manor stands behind a tangle of dead hedges. Its walls are stained and\nits windows are blind.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room380", "south",
  });
}
