inherit "room/room";

void create() {
  ::create();

    short_desc = "Empty Hall";
    long_desc = "A long chamber holds only the outline of former sleeping spaces, now dusted gray. Moisture streaks the walls, and the floorboards creak under a film of grit.";
    dest_dir = ([
      "west":"/chapter/prologue/area/ruined/room741",
    ]);

  set_light(1);
}

