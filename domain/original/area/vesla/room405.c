inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Temple of Amaterasu";
    long_desc = "PHASE0: a temple of worship";
    dest_dir = ({
        "domain/original/area/vesla/room404", "west",
        "domain/original/area/vesla/room407", "south",
        "domain/original/area/vesla/room406", "north",
    });
}

