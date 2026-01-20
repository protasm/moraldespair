inherit "room/room";

void create() {
  ::create();

    short_desc = "Silent Way";
    long_desc = "The way crosses another street in a small square of worn stone. Old foundations crowd the corners, their rooms open and empty. Wind moves freely through the gaps.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room740",
      "west":"/chapter/prologue/area/ruined/room191",
      "east":"/chapter/prologue/area/ruined/room189",
      "north":"/chapter/prologue/area/ruined/room741",
    ]);

  set_light(1);
}


