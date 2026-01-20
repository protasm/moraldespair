inherit "room/room";

void create() {
  ::create();

    short_desc = "Stone Shaft";
    long_desc = "A circular stone shaft yawns in the floor, its lip chipped and stained with lime. The old windlass is gone, leaving only rusted bolts and a stale breath of damp below.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room765", "southwest",
        "chapter/prologue/area/ruined/room771", "east",
        "chapter/prologue/area/ruined/room768", "west",
    });

  set_light(1);
}

