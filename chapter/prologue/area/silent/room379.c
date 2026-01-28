inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Gravel Rise";
  long_desc = "The gravel path climbs a slope scattered with loose stone. It narrows where\nthe hill has begun to slip.\n";
  dest_dir = ([
    "east":"/chapter/prologue/area/silent/room380",
    "west":"/chapter/prologue/area/silent/room378",
  ]);

  set_light(1);
}
