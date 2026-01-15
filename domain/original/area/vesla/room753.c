inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The drawbridge";
    long_desc = "PHASE0: a drawbridge, left open";
    dest_dir = ({
        "domain/original/area/vesla/room169", "southwest",
        "domain/original/area/vesla/room754", "north",
    });
}

