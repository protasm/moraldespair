inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Rutted Street";
  long_desc = "Deep ruts crease the old street, packed with silt and stray grass. Collapsed\ncurbs and leaning posts hint at buildings beyond the weeds.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room286", "west",
    "domain/original/area/exedoria/room288", "east",
    "domain/original/area/exedoria/room330", "south",
  });
}
