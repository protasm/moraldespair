inherit "room/room";

void create() {
  ::create();

    short_desc = "Stone Shaft";
    long_desc = "A circular stone shaft yawns in the floor, its lip chipped and stained with lime. The old windlass is gone, leaving only rusted bolts and a stale breath of damp below.";
    dest_dir = ([
      "southwest":"/chapter/prologue/area/ruined/room765",
      "east":"/chapter/prologue/area/ruined/room771",
      "west":"/chapter/prologue/area/ruined/room768",
    ]);

  set_light(1);
}

