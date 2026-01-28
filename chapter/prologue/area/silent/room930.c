inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Workshop";
  long_desc = "A heavy room holds idle mechanisms, their belts long rotted away. Oil stains\nand rust mark the floor.\n";
  dest_dir = ([
    "down":"/chapter/prologue/area/silent/room929",
  ]);

  set_light(1);
}
