inherit "room/room";

void create() {
  ::create();

  short_desc = "Gray Foyer";
  long_desc = "A gray stone foyer holds a cold stillness. Damp stains stripe the walls from\nfloor to lintel.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room917",
    "north":"/chapter/prologue/area/silent/room915",
  ]);

  set_light(1);
}
