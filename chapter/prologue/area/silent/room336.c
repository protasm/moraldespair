inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Stone Street";
  long_desc = "The street here is broad, its stones worn smooth in places. Small piles of\nrubble mark fallen doorways.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/silent/room335",
    "east":"/chapter/prologue/area/silent/room337",
    "north":"/chapter/prologue/area/silent/room602",
  ]);

  set_light(1);
}
