inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Stone Shaft";
    long_desc = "A circular stone shaft yawns in the floor, its lip chipped and stained\n"
                + "with lime. The old windlass is gone, leaving only rusted bolts and a\n"
                + "stale breath of damp below.\n";
    dest_dir = ({
        "domain/original/area/vesla/room765", "southwest",
        "domain/original/area/vesla/room771", "east",
        "domain/original/area/vesla/room768", "west",
    });
}

