inherit "room/room";

void create() {
  ::create();

    short_desc = "Bare Bunks";
    long_desc = "The room is divided by low rails where thin beds once rested in rows. Mildew and rot soften the timbers, and the air lies flat and stale.";
    dest_dir = ([
      "west":"/chapter/prologue/area/ruined/room751",
      "down":"/chapter/prologue/area/ruined/room741",
      "south":"/chapter/prologue/area/ruined/room752",
      "east":"/chapter/prologue/area/ruined/room750",
      "north":"/chapter/prologue/area/ruined/room749",
    ]);

  set_light(1);
}

