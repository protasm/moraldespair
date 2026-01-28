inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Stone Street";
  long_desc = "A straight street runs between low walls and empty storefronts. Loose grit\ncrunches over the paving.\n";
  dest_dir = ([
    "east":"/chapter/prologue/area/silent/room336",
    "west":"/chapter/prologue/area/silent/room334",
  ]);

  set_light(1);
}
