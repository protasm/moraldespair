inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Park Edge";
  long_desc = "The park path begins among low shrubs and toppled benches. Grass has pushed\nthrough the paving stones.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room291",
    "north":"/chapter/prologue/area/silent/room371",
  ]);

  set_light(1);
}
