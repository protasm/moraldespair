inherit "room/room";

void create() {
  ::create();

  short_desc = "Lower Office";
  long_desc = "Long desks sit in a row, their legs sunk into a drift of dust. A rusted bell and cracked inkwells remain, and mildew has spread along the baseboards.";
  dest_dir = ([
    "up":"/chapter/prologue/area/ruined/room833",
    "down":"/chapter/prologue/area/ruined/room822",
    "west":"/chapter/prologue/area/ruined/room832",
  ]);

  set_light(1);
}
