inherit "room/room";

void create() {
  ::create();

  short_desc = "Rutted Street";
  long_desc = "Ruts and puddled clay mark the old path between low walls. Scattered rubble\nsuggests a long abandoned block.\n";
  dest_dir = ([
    "east":"/chapter/prologue/area/silent/room295",
    "west":"/chapter/prologue/area/silent/room293",
  ]);

  set_light(1);
}
