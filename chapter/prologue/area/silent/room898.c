inherit "room/room";

void create() {
  ::create();

  short_desc = "Stone Walk";
  long_desc = "The path narrows where rubble has spilled from a broken stair. Dust and grit\nsoften the once-sharp edges.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room899",
    "north":"/chapter/prologue/area/silent/room897",
  ]);

  set_light(1);
}
