inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Fighter's Guild";
    long_desc = "PHASE0: a combat-training guild";
    dest_dir = ({
        "domain/original/area/vesla/room156", "west",
    });
}

