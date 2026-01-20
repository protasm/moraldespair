inherit "room/room";

void create() {
  ::create();

  short_desc = "Chalked Loft";
  long_desc = "A narrow stair ends in a loft where a worktable sits split and furred with mildew. Blackened candle stubs and cracked lenses lie in drifts of dust, hinting at old study now drowned in silence and rot.";
  dest_dir = ([
    "west":"/chapter/prologue/area/ruined/room397",
  ]);

  set_light(1);
}
