inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "High Path";
  long_desc = "This path runs along a raised embankment of cracked stone. The drop to either\nside is softened by weeds.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room373",
    "north":"/chapter/prologue/area/silent/room375",
  ]);

  set_light(1);
}
