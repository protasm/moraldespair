inherit "room/room";

void create() {
  ::create();

    short_desc = "Low Pens";
    long_desc = "Low pen walls barely stand, their joints loose and sagging. Mildew freckles the timbers, and a damp chill clings to the floor.";
    dest_dir = ([
      "southeast":"/chapter/prologue/area/ruined/room779",
      "south":"/chapter/prologue/area/ruined/room783",
      "west":"/chapter/prologue/area/ruined/room776",
      "east":"/chapter/prologue/area/ruined/room778",
      "north":"/chapter/prologue/area/ruined/room780",
    ]);

  set_light(1);
}

