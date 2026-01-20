inherit "room/room";

void create() {
  ::create();

    short_desc = "Silent Way";
    long_desc = "Fragments of carved stone lie half-buried along the edges of the lane, their markings softened by time. A faint ridge of sand has collected against the eastern curb.";
    dest_dir = ([
      "west":"/chapter/prologue/area/ruined/room189",
      "east":"/chapter/prologue/area/ruined/room187",
      "north":"/chapter/prologue/area/ruined/room738",
    ]);

  set_light(1);
}


