inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Ruined Post";
  long_desc = "A small guard niche sits beside the street, its roof fallen in. A rusted bell\nlies in the debris.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room316",
    "north":"/chapter/prologue/area/silent/room926",
  ]);

  set_light(1);
}
