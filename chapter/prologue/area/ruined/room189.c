inherit "room/room";

void create() {
  ::create();

    short_desc = "Silent Way";
    long_desc = "The paving here is uneven, with gaps where stones have been pulled free or sunk. A narrow passage to the south is choked with grit and a slow spread of grass.";
    dest_dir = ([
      "west":"/chapter/prologue/area/ruined/room190",
      "east":"/chapter/prologue/area/ruined/room188",
      "south":"/chapter/prologue/area/ruined/room739",
    ]);

  set_light(1);
}


