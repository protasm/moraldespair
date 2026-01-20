inherit "room/room";

void create() {
  ::create();

    short_desc = "Tack Hooks";
    long_desc = "Crooked hooks line the wall, empty but scarred by long use. The boards are warped and blackened with damp, and the air is still and rank.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room787",
      "west":"/chapter/prologue/area/ruined/room773",
      "east":"/chapter/prologue/area/ruined/room775",
      "north":"/chapter/prologue/area/ruined/room786",
    ]);

  set_light(1);
}

