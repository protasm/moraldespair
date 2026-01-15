inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Tack Hooks";
    long_desc = "Crooked hooks line the wall, empty but scarred by long use. The boards\n"
                + "are warped and blackened with damp, and the air is still and rank.\n";
    dest_dir = ({
        "domain/original/area/vesla/room787", "south",
        "domain/original/area/vesla/room773", "west",
        "domain/original/area/vesla/room775", "east",
        "domain/original/area/vesla/room786", "north",
    });
}

