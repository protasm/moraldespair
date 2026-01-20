inherit "room/room";

void create() {
  ::create();

    short_desc = "Silent Way";
    long_desc = "A long row of broken pillars lines the north side of the way, each stump dark with weathering. The ground is littered with slate chips and fine dust.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room742",
      "west":"/chapter/prologue/area/ruined/room192",
      "east":"/chapter/prologue/area/ruined/room190",
      "north":"/chapter/prologue/area/ruined/room743",
    ]);

  set_light(1);
}


