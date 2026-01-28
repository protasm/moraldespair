inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Empty Kitchen";
  long_desc = "A small dining room opens into a bare kitchen. The counters are bare and the\nhearth is cold.\n";
  dest_dir = ([
    "north":"/chapter/prologue/area/silent/room302",
  ]);

  set_light(1);
}
