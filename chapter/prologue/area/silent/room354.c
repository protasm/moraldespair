inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Broken Walls";
  long_desc = "Fragments of wall stand like ribs around a roofless room. The open sky looks\ndown on rubble and weeds.\n";
  dest_dir = ([
    "east":"/chapter/prologue/area/silent/room312",
  ]);

  set_light(1);
}
