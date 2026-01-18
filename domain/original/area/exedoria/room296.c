inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Rutted Street";
  long_desc = "Dry mud fills the depressions in the street. Thistles and briars knot along\nthe broken verge.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room297", "east",
    "domain/original/area/exedoria/room295", "west",
  });
}
