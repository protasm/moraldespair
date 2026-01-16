inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Park Edge";
  long_desc = "The park path begins among low shrubs and toppled benches. Grass has pushed\nthrough the paving stones.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room291", "south",
    "domain/original/area/exedoria/room371", "north",
  });
}
