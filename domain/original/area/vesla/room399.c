inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Retired Warrior's House";
    long_desc = "PHASE0: a humble home";
    dest_dir = ({
        "domain/original/area/vesla/room734", "up",
        "domain/original/area/vesla/room213", "west",
    });
}

