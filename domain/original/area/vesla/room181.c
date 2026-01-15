inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Eastern End of Wall Street";
    long_desc = "PHASE0: a cobble-stone street below and interior to the exterior city wall";
    dest_dir = ({
        "domain/original/area/vesla/room180", "east",
        "domain/original/area/vesla/room182", "west",
    });
}

