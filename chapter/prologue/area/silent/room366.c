inherit "room/room";

void create() {
  ::create();

  short_desc = "Silent Shop";
  long_desc = "This narrow shop is lined with empty hooks and dark stains. The air is stale\nand sweet with old rot.\n";
  dest_dir = ([
    "north":"/chapter/prologue/area/silent/room289",
  ]);

  set_light(1);
}
