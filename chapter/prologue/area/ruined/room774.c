inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Tack Hooks";
    long_desc = "Crooked hooks line the wall, empty but scarred by long use. The boards are warped and blackened with damp, and the air is still and rank.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room787", "south",
        "chapter/prologue/area/ruined/room773", "west",
        "chapter/prologue/area/ruined/room775", "east",
        "chapter/prologue/area/ruined/room786", "north",
    });
}

