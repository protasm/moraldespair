inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Stone Street";
  long_desc = "A stretch of street opens toward a cluster of ruined roofs. Shadows gather\nwhere eaves once held light.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room339", "west",
    "domain/original/area/exedoria/room341", "east",
    "domain/original/area/exedoria/room343", "south",
  });
}
