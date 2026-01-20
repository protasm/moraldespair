inherit "room/room";

void create() {
  ::create();

    short_desc = "Cold Hearth";
    long_desc = "A broad stone hearth squats in the center, dark with soot and long without heat. An anvil stump and iron tools sit rusted among cinders and damp ash.";
    dest_dir = ([
      "east":"/chapter/prologue/area/ruined/room772",
      "west":"/chapter/prologue/area/ruined/room769",
    ]);

  set_light(1);
}

