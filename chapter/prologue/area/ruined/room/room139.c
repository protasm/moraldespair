inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Basalt Avenue";
  long_desc = "The avenue bends around sagging walls, the basalt setts uneven and underfoot. Moss clings in the seams, and broken steps lead into silent, collapsed doorways.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room/room140",
    "west":"/chapter/prologue/area/ruined/room/room853",
    "east":"/chapter/prologue/area/ruined/room/room854",
    "north":"/chapter/prologue/area/ruined/room/room138",
  ]);

}
