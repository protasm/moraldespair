inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Stone Street";
  long_desc = "A stretch of street opens toward a cluster of ruined roofs. Shadows gather\nwhere eaves once held light.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/silent/room339",
    "east":"/chapter/prologue/area/silent/room341",
    "south":"/chapter/prologue/area/silent/room343",
  ]);

  set_light(1);
}
