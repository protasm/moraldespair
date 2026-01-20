inherit "room/room";

void create() {
  ::create();

  short_desc = "Blackened Court";
  long_desc = "The court is a hollow of scorched brick and collapsed awnings, silent and ruined. Mildew blooms on low walls, and rot mixes with dust around broken stalls left to crumble.";
  dest_dir = ([
    "west":"/chapter/prologue/area/ruined/room844",
    "south":"/chapter/prologue/area/ruined/room841",
    "north":"/chapter/prologue/area/ruined/room201",
  ]);

  set_light(1);
}
