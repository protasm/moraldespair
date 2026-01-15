inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Wall Street";
    long_desc = "PHASE0: a cobble-stone street below and interior to the exterior city wall";
    dest_dir = ({
        "domain/original/area/vesla/room181", "east",
        "domain/original/area/vesla/room183", "west",
    });
}

