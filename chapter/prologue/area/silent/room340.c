inherit "room/room";

void create() {
  ::create();

  short_desc = "Stone Street";
  long_desc = "A stretch of street opens toward a cluster of ruined roofs. Shadows gather\nwhere eaves once held light.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room339", "west",
    "chapter/prologue/area/silent/room341", "east",
    "chapter/prologue/area/silent/room343", "south",
  });

  set_light(1);
}
