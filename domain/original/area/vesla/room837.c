inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Open Air Market:";
    long_desc = "PHASE0: a small market";
    dest_dir = ({
        "domain/original/area/vesla/room422", "west",
    });
}

