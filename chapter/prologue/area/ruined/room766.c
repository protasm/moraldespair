inherit "room/room";

void create() {
  ::create();

  short_desc = "Stone Court";
  long_desc = "Cold stone surrounds this open court, with mildew streaks and fallen chips whitening the ground. A shallow channel in the paving runs toward a broken drain, a remnant of tidy upkeep.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room758", "southeast",
    "chapter/prologue/area/ruined/room757", "south",
    "chapter/prologue/area/ruined/room768", "northeast",
    "chapter/prologue/area/ruined/room765", "east",
    "chapter/prologue/area/ruined/room767", "north",
  });

  set_light(1);
}
