inherit "room/room";

void create() {
  ::create();

  short_desc = "Stone Court";
  long_desc = "Cold stone surrounds this open court, with mildew streaks and fallen chips whitening the ground. A shallow channel in the paving runs toward a broken drain, a remnant of tidy upkeep.";
  dest_dir = ([
    "southeast":"/chapter/prologue/area/ruined/room758",
    "south":"/chapter/prologue/area/ruined/room757",
    "northeast":"/chapter/prologue/area/ruined/room768",
    "east":"/chapter/prologue/area/ruined/room765",
    "north":"/chapter/prologue/area/ruined/room767",
  ]);

  set_light(1);
}
