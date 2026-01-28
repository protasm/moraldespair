inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Common Hall";
  long_desc = "Long tables stand in a wide hall, their surfaces split and gray. A cold hearth\nsits at the far end.\n";
  dest_dir = ([
    "north":"/chapter/prologue/area/silent/room894",
  ]);

  set_light(1);
}
