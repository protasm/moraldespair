inherit "room/room";

void create() {
  ::create();

    short_desc = "Silent Way";
    long_desc = "The lane ends at a wider crossing, its stones paling where sunlight reaches in. A toppled capstone rests near the curb, half sunk in silt.";
    dest_dir = ([
      "west":"/chapter/prologue/area/ruined/room166",
      "east":"/chapter/prologue/area/ruined/room191",
      "south":"/chapter/prologue/area/ruined/room744",
    ]);

  set_light(1);
}


