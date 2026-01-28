inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Stone Walk";
  long_desc = "A formal walkway continues between shuttered halls. Only wind and birds move\namong the stones.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room902",
    "east":"/chapter/prologue/area/silent/room900",
    "north":"/chapter/prologue/area/silent/room898",
  ]);

  set_light(1);
}
